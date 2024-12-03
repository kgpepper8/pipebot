//tasks.c

bool drive(float dist, bool direction, bool toStop, int speed,
		   float &currentdist, int &time, TFileHandle &logfile) {
	bool isMoving = true;
	string mesg = "";

	nMotorEncoder[FDRIVE] = 0;

	if(direction) {
		motor[FDRIVE] = speed;
		motor[RDRIVE] = -speed;
	} else {
		motor[FDRIVE] = -speed;
		motor[RDRIVE] = speed;
	}

	while((abs(nMotorEncoder[FDRIVE]) <= dist * CONV)) {}

	float acc2 = abs(SensorValue[ACCPORT]);
	sendLog(logfile, time, mesg, acc2);

	if (direction){
		if (acc2 > MINACCEL) {
			isMoving = true;
			currentdist += dist;
		}
		else {
			mesg = "Failed to drive.";
			sendLog(logfile, time, mesg);
			isMoving = false;
		}
	}
	else {
		currentdist -= dist;
	}

	if(toStop) {
		motor[FDRIVE] = motor[RDRIVE] = 0;
	}

	return isMoving;
}

void tensionWheels(int &pastRotations, bool spinDown) {
	if(!spinDown) {
		nMotorEncoder[LDSCREW] = 0;
		motor[LDSCREW] = -100;
		while(nMotorEncoder[LDSCREW] < LDSCREWROTS){}
		motor[LDSCREW] = 0;
		pastRotations += nMotorEncoder[LDSCREW];
  	}
  	else {
  		nMotorEncoder[LDSCREW] = 0;
  		motor[LDSCREW] = 100;
    	while(abs(nMotorEncoder[LDSCREW]) < pastRotations){}
    	motor[LDSCREW] = 0;
 	}
}

bool clean(float &currentdist, int &time, TFileHandle &logfile) {
	string mesg = "";
	int failures = 0;

	for(int i = 0; i < HITS; i++) {
		mesg = "Started cleaning";
		sendLog(logfile, time, mesg);

		drive(15, 0, 1, SPEEDLOW, currentdist, time, logfile);
		mesg = "Reversing: ";
		sendLog(logfile, time, mesg, i);

		motor[BRUSH] = 100;
		mesg = "Spinning up brush";
		sendLog(logfile, time, mesg);

		wait1Msec(1000);

		while (SensorValue(TOUCHPORT) != 1){
			mesg = "Ramming";
			sendLog(logfile, time, mesg);
			if(!drive(DRIVEDIST, 1, 0, SPEEDRAM, currentdist, time, logfile)){
				failures++;
				mesg = "Clean failures now at: ";
				sendLog(logfile, time, mesg, failures);
				if (failures >= MAXFAIL){
					motor[BRUSH] = 0;
					return false;
				}
			}
		}
		drive(5, 1, 1, SPEEDRAM, currentdist, time, logfile);
		wait1Msec(1000);

		if(!ultrasonicDist()){
			motor[BRUSH] = 0;
			return true;
    }
 	}

 	motor[BRUSH] = 0;
 	return false;
}

void escape(float &currentdist, int &time, TFileHandle &logfile) {
	bool acceltrue = true;
	int failures = 0;

	drive(0, 0, 1, 0, currentdist, time, logfile);

	while ((currentdist > DISTTOLEAVE) && acceltrue) {
		if (!drive(DRIVEDIST, 0, 0, SPEEDHIGH, currentdist, time, logfile)) {
			if (failures > MAXFAIL){
				acceltrue = false;
			}
			else {
				failures++;
			}
		}
	}

	if (!acceltrue) {
		string message = "Mission Failure: Shutting Down.";
		sendLog(logfile, time, message);
	}
	else {
		string message = "Escaping.";
		sendLog(logfile, time, message);

		while(!getButtonPress(buttonAny)) {
			drive(DRIVEDIST, 0, 0, SPEEDLOW, currentdist, time, logfile);
		}
	}
	drive(0, 0, 1, 0, currentdist, time, logfile);
}

void shutdown(int &pastRotations, int &time, TFileHandle &logfile) {
	tensionWheels(pastRotations, 1);
	string mesg = "Shut down.";
	sendLog(logfile, time, mesg);
}
