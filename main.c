//main.c
#include "tasks.c"

//holds the distance, in cm, driven between health checks
const float DRIVEDIST = 5;

/*
No parameters. 
Returns a float corresponding to the distance the user entered on the screen.
*/
float getUserDistance();

/*
No parameters.
Initializes and resets sensors, then returns 1 if it succeeded and 0 if it failed.
*/
bool initializeSensors();

//main function
task main(){
	initializeSensors();
	
	float endpoint = getUserDistance();
	
	mainLoop(endpoint, DRIVEDIST)
}