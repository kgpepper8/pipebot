//startup.c

float getUserDistance() {
	float maxdist = 0;

	while (!getButtonPress(buttonEnter)) {
		displayString(10, "Distance to clear: %1.2f", maxdist);
		if (getButtonPress(buttonUp)) {
			maxdist += 10;
			while(getButtonPress(buttonAny)){}
		} else if(getButtonPress(buttonDown) && maxdist >= 10) {
			maxdist -=10;
			while(getButtonPress(buttonAny)){}
		}
	}
	displayString(5, "Distance to clear: %f", maxdist);
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
