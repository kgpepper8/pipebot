//sensor locations
	const tSensors USPORT = S1;
	const tSensors ACCPORT = S2;
	const tSensors TOUCHPORT = S3;

//motor locations
	const tMotor FDRIVE = motorA;
	const tMotor RDRIVE = motorB;
	const tMotor BRUSH = motorC;
	const tMotor LDSCREW = motorD;

//holds the desired name of the logfile
	const string LOGNAME = "log.txt";

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
