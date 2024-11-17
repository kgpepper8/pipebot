//tasks.c

bool drive(float dist, bool direction, bool toStop, int speed, float &currentdist, int &time) {
	bool isMoving;

	nMotorEncoder[FDRIVE] = 0;

	if(direction) {
		motor[FDRIVE] = speed;
		motor[RDRIVE] = -speed;
	} else {
		motor[FDRIVE] = -speed;
		motor[RDRIVE] = speed;
	}

	while(nMotorEncoder[FDRIVE] * CONV <= dist) {}

	float acc2 = SensorValue[ACCPORT];

	if (acc2 > MINACCEL) { //arbitrairy acceleration val, change later
		isMoving = true;
	} else {
		isMoving = false;
	}

	if(toStop) {
		motor[FDRIVE] = motor[RDRIVE] = 0;
	}

	string mesg = "Drove a distance of: ";
	sendLog(time, mesg, dist);

	return isMoving;
}

void tensionWheels(int &pastRotations, bool spinDown) {
	if(!spinDown) {
		nMotorEncoder[LDSCREW] = 0;
		motor[LDSCREW] = 100;
		while(nMotorEncoder[LDSCREW] < LDSCREWROTS){}
		motor[LDSCREW] = 0;
		pastRotations += nMotorEncoder[LDSCREW];
  }
  else {
  	nMotorEncoder[LDSCREW] = 0;
  	motor[LDSCREW] = -100;
    while(abs(nMotorEncoder[LDSCREW]) < pastRotations){}
    motor[LDSCREW] = 0;
 	}
}

bool clean(float &currentdist, int &time) {
	for(int i = 0; i < HITS; i++) {

		drive(25, 0, 1, SPEEDLOW, currentdist, time);

		motor[BRUSH] = 100;
		wait1Msec(1000);

		while (SensorValue(TOUCHPORT) != 1){
			drive(1, 1, 0, SPEEDRAM, currentdist, time);
		}
		drive(5, 1, 1, SPEEDRAM, currentdist, time);
		wait1Msec(1000);

		if(!ultrasonicDist()){
			return true;
    }
 	}
 	return false;
}

void escape(float &currentdist, int &time) {
	bool acceltrue = true;

	while ((currentdist > DISTTOLEAVE) && acceltrue) {
		if (!drive(DRIVEDIST, 0, 0, SPEEDHIGH, currentdist, time)) {
			acceltrue = false;
		}
	}

	if (!acceltrue) {
		string message = "Mission Failure: Shutting Down.";
		sendLog(time, message);
	}
	else {
		setSoundVolume(100);
		playSoundFile("Robotexitnoise.mp3");

		string message = "Escaping.";
		sendLog(time, message);

		while(!getButtonPress(buttonAny)) {
			drive(DRIVEDIST, 0, 0, SPEEDLOW, currentdist, time);
		}
	}
	drive(0, 0, 1, SPEEDLOW, currentdist, time);
}

void shutdown(int &pastRotations, int &time) {
	tensionWheels(pastRotations, 1);
	string mesg = "Shut down.";
	sendLog(time, mesg);
}
