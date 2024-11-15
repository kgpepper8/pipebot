//implemented in startup.c
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
	void initializeSensors();

//implemented in logger.c
	#include "fileLib/PC_FileIO.c"

	/*
	Author: Samuel Mailhot
	No parameters.
	Creates or opens, then returns, a logfile with the proper name.
	*/
	TFileHandle prepLog();

	/*
	Author: Kiran Ghanekar
	Parameters: int time (the log's timestamp)
							string msg (the message to be written)
							(optional) float numarg (a numerical thing to log, may or may not be needed)
	No returns. Writes a log message to the file returned by prepLog().
	*/
	void sendLog(int time, string mesg);
	void sendLog(int time, string mesg, float &numarg);

//implemented in tasks.c
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
	bool drive(float dist, bool direction, bool toStop, int speed, float &currentdist, int &time);

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
	bool clean(float &currentdist, int &time);

	/*
	Author: Stefan Mathies
	Parameters: float currentdist (the distance into the pipe the robot has travelled)
	No returns - runs the escape procedure in accordance with the flowchart.
	*/
	void escape(float &currentdist, int &time);

	/*
	Author: Stefan Mathies
	No returns - runs the shutdown procedure in accordance with the flowchart.
	*/
	void shutdown(int &pastRotations, int &time);

//implemented in checks.c
	/*
	Author: Kiran Ghanekar
	No parameters.
	Returns whether or not a blockage is noticed or not.
	*/
	bool ultrasonicDist();

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
	int healthCheck(float &currentdist, float &endpoint, bool didDrive, float drivedist, int &time);
