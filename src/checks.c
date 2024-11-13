//checks.c

/*
Author: Emily D'Silva
No parameters.
Returns 1 if all sensors are working, otherwise returns 0.
*/
bool checkSensors();

/*
Author: Kiran Ghanekar
No parameters.
Returns the distance from the front of the robot to the nearest obstacle based on the ultrasonic sensor reading.
*/
float ultrasonicDist();

/*
Author: Kiran Ghanekar
Parameters: float &currentdist (reference to a variable holding the distance moved by the robot since power-on)
			float endpoint (the user-input endpoint)
			bool didDrive (whether or not the robot moved, from the accelerometer)
			float drivedist (the distance to drive before each health check)
			int time (the current time counter)
Returns: 0 if everything passes
		 1 if the robot should start to leave the pipe
		 5 if the robot should start cleaning operations
		 10 if the robot should tension the wheels more
*/
int healthCheck(float &currentdist, float &endpoint, float &acceldist, float drivedist, int time);

/* function implementations below this line ----------------------------------- */

bool checkSensors(){

}

float ultrasonicDist(){
	return (SensorValue[USPORT]-USOFFSET);
}

int healthCheck(float &currentdist, float &endpoint, bool didDrive, float drivedist, int time){
	int state = 0;

	if (currentdist >= endpoint){
		state = 1;
	}
	else if (didDrive){
		if (checkSensors()) {
			if (ultrasonicDist()){
				state = 5;
			}
		}
		else {
			state = 1;
		}
	}
	else {
		didDrive = drive(drivedist, 0, 1, SPEEDHIGH, currentdist, time);
		if (didDrive) {
			state = 1;
		}
		else {
			state = 10;
		}
	}

	return state;
}
