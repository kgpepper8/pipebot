//main.c
#include "consts.h"
#include "funcs.h"
#include "startup.c"
#include "tasks.c"
#include "checks.c"
#include "logger.c"

/*
Main function.
No returns, no parameters.
*/
task main(){
	TFileHandle logfile = prepLog();

	initializeSensors();

	float endpoint = getUserDistance();
	wait1Msec(5000);

	float currentdist = 0;
	int state = 0, time = 0, pastRotations = 0, failures = 0;
	bool go = true, didDrive = false;

	string mesg = "Robot initialized. Endpoint is ";
	sendLog(logfile, time, mesg, endpoint);

	//main loop
	while (go) {
		time++;
		didDrive = drive(DRIVEDIST, 1, 0, SPEEDHIGH, currentdist, time, logfile);
		state = healthCheck(currentdist, endpoint, didDrive, failures, DRIVEDIST, time, logfile);

		if (state == 10){
			tensionWheels(pastRotations, 0);
			state = 1;
		}
		else if (state == 5){
			if(clean(currentdist, time, logfile)){
				mesg = "Cleaned blockage.";
				sendLog(logfile, time, mesg);
			}
			else {
				state = 1;
				mesg = "Failed cleaning.";
				sendLog(logfile, time, mesg);
			}
		}

		if (state == 1){
			mesg = "Health check failure";
			sendLog(logfile, time, mesg);
			go = false;
		}
	}

	escape(currentdist, time, logfile);
	shutdown(pastRotations, time, logfile);
}
