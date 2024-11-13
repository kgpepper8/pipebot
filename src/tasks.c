//tasks.c

/*
Author: Emily D'Silva
Parameters: float dist (the distance to drive)
			bool direction (1 for forward, 0 for backward)
			bool stop (1 to stop at the end, 0 to keep moving)
			int speed (between 0 and 100)
			float &currentdist (reference to a variable containing how far the robot has advanced)
			int time (an integer corresponding to the current time value)
Returns whether the robot was or was not moving after driving 'dist' in 'direction'.
*/
bool drive(float dist, bool direction, bool toStop, int speed, float &currentdist, int time);

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
void escape(float &currentdist, int time);

/*
Author: Stefan Mathies
No returns - runs the shutdown procedure in accordance with the flowchart.
*/
void shutdown();

/* function implementations below this line ----------------------------------- */

bool drive(float dist, bool direction, bool toStop, int speed, float &currentdist, int time) {

}

void tensionWheels(int &pastRotations, bool spinDown) {

}

bool clean() {

}

void escape(float &currentdist, int time) {
	float partialdistrem = currentdist * (1/3);
	bool acceltrue = true;

	while ((currentdist > partialdistrem) && acceltrue == 1) {
		if (drive(5, 0, 0, SPEEDHIGH, currentdist, time) < 10) //10 to account for error (can change buffer)//
		{
			acceltrue = false;
		}
	}

	if (acceltrue == false)
	{
		displayString(5, "Mission Failure: Shutting Down");
		wait1Msec(10000);
	}
	else
	{
		setSoundVolume(100);
		playSoundFile("Robotexitnoise.mp3");
		while(!getButtonPress(buttonAny) && currentdist != 0){
			drive(5, 0, 0, SPEEDHIGH, currentdist, time);
		}
	drive(0, 0, 1, SPEEDLOW, currentdist, time);
	}
}

void shutdown() {

}
