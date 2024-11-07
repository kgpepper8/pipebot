//main.c
#include "startup.h"
#include "tasks.h"

//holds the distance, in cm, driven between health checks
const float DRIVEDIST = 5;

//main function
task main(){
	initializeSensors();

	float endpoint = getUserDistance();

	mainLoop(endpoint, DRIVEDIST);
}
