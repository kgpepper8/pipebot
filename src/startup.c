//startup.c

float getUserDistance() {
	float maxdist = 0;

	while (!getButtonPress(buttonEnter)) {
		displayString(10, "Distance to clear: %f", maxdist);
		if (getButtonPress(buttonUp)) {
			maxdist += 5;
		} else if(getButtonPress(buttonDown) && maxdist >= 5) {
			maxdist -=5;
		}
	}
	displayString(5, "Distance to clear: %d", maxdist);
	maxdist = maxdist * ((2 * PI * 2.75)/ 360); //Converts distance to motor encoder counts//
	return maxdist;
}

void initializeSensors() {
	SensorType[USPORT] = sensorEV3_Ultrasonic;
	wait1Msec(50);

	SensorType[TOUCHPORT] = sensorEV3_Touch;
	wait1Msec(50);

	nMotorEncoder[FDRIVE] = 0;
	nMotorEncoder[RDRIVE] = 0;
	nMotorEncoder[LDSCREW] = 0;
	nMotorEncoder[BRUSH] = 0;
}
