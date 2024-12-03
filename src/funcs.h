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
	#include "fileLib/PC_FileIO.c" //includes the file library provided by the teaching team

	/*
	Author: Samuel Mailhot
	No parameters.
	Creates, then returns, a logfile with the proper name.
	*/
	TFileHandle prepLog();

	/*
	Author: Kiran Ghanekar
	Parameters: int time (the log's timestamp)
							string msg (the message to be written)
							(optional) float numarg or int numarg
								(a numerical argument to log, may or may not be needed)
	No returns. Writes a log message to the file returned by prepLog().
	*/
	void sendLog(TFileHandle &logfile, int &time, string &mesg);
	void sendLog(TFileHandle &logfile, int &time, string &mesg, float &numarg);
	void sendLog(TFileHandle &logfile, int &time, string &mesg, int &numarg);


//implemented in tasks.c
	/*
	Author: Emily D'Silva
	Parameters: float dist (the distance to drive)
				bool direction (1 for forward, 0 for backward)
				bool toStop (1 to stop at the end, 0 to keep moving)
				int speed (between 0 and 100)
				float &currentdist (reference to a variable containing
									how far the robot has advanced)
				int &time (reference to an integer corresponding to the current time value)
				TFileHandle &logfile (reference to a logfile to write to)
	Returns whether the robot was or was not moving after driving 'dist' in 'direction'.
	*/
	bool drive(float dist, bool direction, bool toStop, int speed,
			   float &currentdist, int &time, TFileHandle &logfile);

	/*
	Author: Samuel Mailhot
	Parameters: int &pastRotations (reference to a variable holding the number of
									times the lead screw has already turned)
				bool spinDown (if true, spin the leadscrew all the way back to 0 rotations)
	No returns - rotates the lead screw a certain amount based on
				 pastRotations to tension the wheels further.
	*/
	void tensionWheels(int &pastRotations, bool spinDown);

	/*
	Author: Samuel Mailhot
	Parameters: float &currentdist (reference to a variable containing
									how far the robot has advanced)
				int &time (reference to an integer corresponding to the current time value)
				TFileHandle &logfile (reference to a logfile to write to)
	Returns 1 if the procedure succeeded, and 0 if it failed.
	*/
	bool clean(float &currentdist, int &time, TFileHandle &logfile);

	/*
	Author: Stefan Mathies
	Parameters: float &currentdist (reference to a variable containing
									how far the robot has advanced)
				int &time (reference to an integer corresponding to the current time value)
				TFileHandle &logfile (reference to a logfile to write to)
	No returns - runs the escape procedure in accordance with the flowchart.
	*/
	void escape(float &currentdist, int &time, TFileHandle &logfile);

	/*
	Author: Stefan Mathies
	Parameters: int &pastRotations (reference to a variable holding the number of
									times the lead screw has already turned)
				int &time (reference to an integer corresponding to the current time value)
				TFileHandle &logfile (reference to a logfile to write to)
	No returns - runs the shutdown procedure in accordance with the flowchart.
	*/
	void shutdown(int &pastRotations, int &time, TFileHandle &logfile);


//implemented in checks.c
	/*
	Author: Kiran Ghanekar
	No parameters.
	Returns whether or not a blockage is within range or not.
	*/
	bool ultrasonicDist();

	/*
	Author: Kiran Ghanekar
	Parameters: float &currentdist (reference to a variable holding the distance
									moved by the robot since power-on)
				float &endpoint (reference to the user-input endpoint)
				bool didDrive (whether or not the robot moved, from the accelerometer)
				int &failures (reference to a variable containing the number of
							   health checks that have already failed)
				float drivedist (the distance to drive before each health check)
				int &time (reference to the current time counter)
				TFileHandle &logfile (reference to a logfile to write to)
	Returns: 0 if everything passes
			 1 if the robot should start to leave the pipe
			 5 if the robot should start cleaning operations
			 10 if the robot should tension the wheels more
	*/
	int healthCheck(float &currentdist, float &endpoint, bool didDrive, int &failures,
					float drivedist, int &time, TFileHandle &logfile);