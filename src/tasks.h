//tasks.h

#ifndef TASKS
	#define TASKS
	#include "tasks.c"
#endif

/*
Author: Kiran Ghanekar
Parameters: float endpoint (the user-defined distance that the robot should advance)
			float drivedist (the distance to drive before each health check)
No returns - coordinates the nominal operation of the robot, as described by the flowchart.
*/
void mainLoop(float endpoint, float drivedist);

/*
Author: Emily D'Silva
Parameters: float dist (the distance to drive)
			bool direction (1 for forward, 0 for backward)
			bool stop (1 to stop at the end, 0 to keep moving)
			float &currentdist (reference to a variable containing how far the robot has advanced)
			int time (an integer corresponding to the current time value)
Returns the distance the accelerometer reports after driving 'dist' in 'direction'.
*/
float drive(float dist, bool direction, bool stop, float &currentdist, int time);

/*
Author: Samuel Mailhot
Parameters: int &pastRotations (reference to a variable holding the number of times the lead screw has already turned)
			bool spinDown (if true, spin the leadscrew all the way back to 0 rotations)
No returns - rotates the lead screw a certain amount based on pastRotations to tension the wheels further.
*/
void tensionWheels(int &pastRotations, bool spinDown);

/*
Author: Samuel Mailhot
No parameters.
Returns 1 if the procedure succeeded, and 0 if it failed.
*/
bool clean();

/*
Author: Stefan Mathies
Parameters: float currentdist (the distance into the pipe the robot has travelled)
No returns - runs the escape procedure in accordance with the flowchart.
*/
void escape(float &currentdist);

/*
Author: Stefan Mathies
No returns - runs the shutdown procedure in accordance with the flowchart.
*/
void shutdown();