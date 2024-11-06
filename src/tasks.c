//tasks.c
#include "logger.c"
#include "checks.c"

//holds the conversion factor for motor encoder count to distance
const float CONV = PI*2.75/180;
const int LSCOUNT; //to be set

/*
Parameters: float endpoint (the user-defined distance that the robot should advance)
			float drivedist (the distance to drive before each health check)
No returns - coordinates the nominal operation of the robot, as described by the flowchart.
*/
void mainLoop(float endpoint, float drivedist);

/*
Parameters: float dist (the distance to drive)
			bool direction (1 for forward, 0 for backward)
			bool stop (1 to stop at the end, 0 to keep moving)
			float &currentdist (reference to a variable containing how far the robot has advanced)
			int time (an integer corresponding to the current time value)
Returns the distance the accelerometer reports after driving 'dist' in 'direction'.
*/
float drive(float dist, bool direction, bool stop, float &currentdist, int time);

/*
No parameters.
No returns - rotates the lead screw by LSCOUNT to tension the wheels further.
*/
void tensionWheels();

/*
No parameters.
No returns - runs the cleaning procedure in accordance with the flowchart.
*/
void clean();

/*
No parameters.
No returns - runs the escape procedure in accordance with the flowchart.
*/
void escape();

/*
No returns - runs the shutdown procedure in accordance with the flowchart.
*/
void shutdown();