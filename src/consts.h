//sensor locations
	const tSensors USPORT = S3;
	const tSensors ACCPORT = S2;
	const tSensors TOUCHPORT = S4;

//motor locations
	const tMotor FDRIVE = motorB;
	const tMotor RDRIVE = motorC;
	const tMotor BRUSH = motorD;
	const tMotor LDSCREW = motorA;

//holds the desired name of the logfile
	const string LOGFILE = "log.txt";

//holds the distance, in cm, driven between health checks
	const float DRIVEDIST = 5;

//holds the distance from the ultrasonic sensor to the front of the robot
	const float USOFFSET = 20;

//holds the conversion factor for motor encoder count to distance
	const float CONV = PI*2.75/180;

//speed constants
	const int SPEEDHIGH = 50;
	const int SPEEDLOW = 25;

//minimum accelration
	const int MINACCEL = 100;

//number of times to ram
	const int HITS = 5;

//distance for something to be considered a blockage
	const int BLOCKDIST = 50;

//how many times to rotate the lead screw for tensioning
	const int LDSCREWROTS = 10;
