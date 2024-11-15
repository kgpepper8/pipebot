//tasks.c

bool drive(float dist, bool direction, bool toStop, int speed, float &currentdist, int &time) {
	bool isMoving;

	nMotorEncoder[motorA] = 0;

	if(direction) {
		motor[motorA] = motor[motorD] = speed;
	} else {
		motor[motorA] = motor[motorD] = -speed;
	}

	while(nMotorEncoder[motorA] <= dist * CONV) {}

	float acc2 = SensorValue(ACCPORT);

	if (acc2 > MINACCEL) { //arbitrairy acceleration val, change later
		isMoving = true;
	} else {
		isMoving = false;
	}

	if(toStop) {
		motor[motorA] = motor[motorD] = 0;
	}

	return isMoving;
}

void tensionWheels(int &pastRotations, bool spinDown) {
	if(!spinDown) {
		nMotorEncoder[LDSCREW] = 0;
		motor[LDSCREW] = 100;
		while(nMotorEncoder[LDSCREW] < 360*LDSCREWROTS){}
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
	// C3 to C6 on the flow chart

	//Blockage was detected, function called
	for(int i = 0; i < HITS; i++) {
		//C2: reverse 25cm - stops
		drive(25, 0, 1, 50, currentdist, time);

		//C3: spin brush (spin motor)
		motor[BRUSH] = 100;
		wait1Msec(1000);

		//Add funny noise
		//C4: Full speed ahead (until blockage hit -  reverse 15 and check for blockage (UltraSonic) if no blockage return 1
		while (SensorValue(TOUCHPORT) != 1){
			drive(1, 1, 0, 100, currentdist, time);
		}
		drive(5, 1, 1, 100, currentdist, time);
		wait1Msec(1000);

		drive(20, 0, 1, 50, currentdist, time);

		if(!ultrasonicDist()){
			return true;
    }
 	}
 	return false;
}

void escape(float &currentdist, int &time) {
	float partialdistrem = currentdist * (1/3);
	bool acceltrue = true;

	while ((currentdist > partialdistrem) && acceltrue == 1) {
		if (drive(5, 0, 0, SPEEDHIGH, currentdist, time)) {
			acceltrue = false;
		}
	}

	if (acceltrue == false) {
		string message = "Mission Failure: Shutting Down";
		sendLog(time, message);
	} else {
		setSoundVolume(100);
		playSoundFile("Robotexitnoise.mp3");
		while(!getButtonPress(buttonAny) && currentdist != 0) {
			drive(5, 0, 0, SPEEDHIGH, currentdist, time);
		}
		drive(0, 0, 1, SPEEDLOW, currentdist, time);
	}
}

void shutdown(int &pastRotations, int &time) {
	tensionWheels(pastRotations, 1);
	string mesg = "Shut down.";
	sendLog(time, mesg);
}
