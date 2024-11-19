//sensor locations
	const tSensors USPORT = S1;
	const tSensors ACCPORT = S3;
	const tSensors TOUCHPORT = S2;

//motor locations
	const tMotor FDRIVE = motorA;
	const tMotor RDRIVE = motorB;
	const tMotor BRUSH = motorC;
	const tMotor LDSCREW = motorC;

//holds the distance, in cm, driven between health checks
	const float DRIVEDIST = 5;

//holds the distance from the ultrasonic sensor to the front of the robot
	const float USOFFSET = 20;

//holds the conversion factor for motor encoder count to distance
	const float CONV = 180*2.75/PI;

//speed constants
	const int SPEEDRAM = 100;
	const int SPEEDHIGH = 50;
	const int SPEEDLOW = 25;

//minimum accelration to be considered moving
	const int MINACCEL = 100;

//number of times to attempt cleaning
	const int HITS = 5;

//distance for something to be considered a blockage
	const int BLOCKDIST = 25;

//how many times to rotate motor for tensioning
	const int LDSCREWROTS = 10 * 360 * 24;

//what distance to leave at the end while escaping
	const int DISTTOLEAVE = 30;
