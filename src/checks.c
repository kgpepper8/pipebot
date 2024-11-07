//checks.c
#include "sensors.h"

//holds the max tolerable difference between the accelerometer and the motor enconders
const float TOLERANCE = 0.5;

//holds the distance from the ultrasonic sensor to the front of the robot
const float USOFFSET = 20;

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
			float acceldist (the most recent distance reported by the drive function, from the accelerometer)
			float drivedist (the distance to drive before each health check)
			int time (the current time counter)
Returns: 0 if everything passes
		 1 if the robot should start to leave the pipe
		 5 if the robot should start cleaning operations
		 10 if the robot should tension the wheels more
*/
int healthCheck(float &currentdist, float endpoint, float acceldist, float drivedist, int time);

/* function implementations below this line ----------------------------------- */

bool checkSensors(){

}

float ultrasonicDist(){
	return (SensorValue[USPORT]-USOFFSET);
}

int healthCheck(float &currentdist, float endpoint, float acceldist, float drivedist, int time){
	int state = 0;

	if (currentdist >= endpoint){
		state = 1;
	}
	else if (abs(acceldist-drivedist) <= TOLERANCE){
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
		acceldist = drive(drivedist, 0, 1, currentdist, time);
		if (abs(acceldist-drivedist) <= TOLERANCE) {
			state = 1;
		}
		else {
			state = 10;
		}
	}

	return state;
}
