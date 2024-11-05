//checks.c

/*
No parameters.
Returns 1 if all sensors are working, otherwise returns 0.
*/
bool checkSensors();

/*
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
int healthCheck(&currentdist, endpoint, acceldist, drivedist, time);