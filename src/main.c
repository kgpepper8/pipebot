//main.c
#include "logger.c"
#include "tasks.c"
#include "checks.c"
#include "startup.c"

//holds the distance, in cm, driven between health checks
const float DRIVEDIST = 5;

/*
Author: Kiran Ghanekar
No parameters.
No returns - coordinates the nominal operation of the robot, as described by the flowchart.
*/
task main(){
	initializeSensors();

	float endpoint = getUserDistance();

	float currentdist = 0, acceldist = 0;
	int state = 0, time = 0, pastRotations = 0;
	bool go = true;

	string mesg = "Robot initialized. Endpoint is ";
	sendLog(time, mesg, endpoint);

	//main loop
	while (go) {
		time++;
		acceldist = drive(DRIVEDIST, 1, 0, currentdist, time);
		state = healthCheck(currentdist, endpoint, acceldist, DRIVEDIST, time);
		if (state == 10){
			tensionWheels(pastRotations, 0);
		}
		else if (state == 5){
			clean();
		}
		else if (state == 1){
			go = false;
		}
	}

	escape(currentdist);
	shutdown();
}
