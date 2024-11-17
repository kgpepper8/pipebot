//main.c
#include "consts.h"
#include "funcs.h"
#include "startup.c"
#include "tasks.c"
#include "checks.c"
#include "logger.c"

/*
Author: Kiran Ghanekar
No parameters.
No returns - coordinates the nominal operation of the robot, as described by the flowchart.
*/
task main(){
	initializeSensors();

	float endpoint = getUserDistance();

	float currentdist = 0;
	int state = 0, time = 0, pastRotations = 0;
	bool go = true, didDrive = false;

	string mesg = "Robot initialized. Endpoint is ";
	sendLog(time, mesg, endpoint);

	//main loop
	while (go) {
		time++;
		didDrive = drive(DRIVEDIST, 1, 0, SPEEDHIGH, currentdist, time);
		state = healthCheck(currentdist, endpoint, didDrive, DRIVEDIST, time);

		if (state == 10){
			tensionWheels(pastRotations, 0);
			mesg = "Tensioned wheels.";
			sendLog(time, mesg);
		}
		else if (state == 5){
			if(clean(currentdist, time)){
				mesg = "Cleaned blockage.";
				sendLog(time, mesg);
			}
			else {
				state = 1;
			}
		}
		else if (state == 1){
			go = false;
		}
	}

	escape(currentdist, time);
	shutdown(pastRotations, time);
}
