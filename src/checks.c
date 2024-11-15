//checks.c

bool ultrasonicDist(){
	return (SensorValue[USPORT]-USOFFSET) < BLOCKDIST;
}

int healthCheck(float &currentdist, float &endpoint, bool didDrive, float drivedist, int &time){
	int state = 0;

	if (currentdist >= endpoint){
		state = 1;
	}
	else if (didDrive){
		if (ultrasonicDist() < BLOCKDIST){
			state = 5;
		}
		else {
			state = 1;
		}
	}
	else {
		didDrive = drive(drivedist, 0, 1, SPEEDHIGH, currentdist, time);
		if (didDrive) {
			state = 1;
		}
		else {
			state = 10;
		}
	}

	return state;
}
