//startup.h

#ifndef STARTUP
	#define STARTUP
	#include "startup.c"
#endif

/*
Author: Stefan Mathies
No parameters. 
Returns a float corresponding to the distance the user entered on the screen.
*/
float getUserDistance();

/*
Author: Emily D'Silva
No parameters.
Initializes and resets sensors, then returns 1 if it succeeded and 0 if it failed.
*/
bool initializeSensors();
