//checks.c

bool ultrasonicDist(){
	return (SensorValue[USPORT]-USOFFSET) < BLOCKDIST;
}

int healthCheck(float &currentdist, float &endpoint, bool didDrive, int &failures,
				float drivedist, int &time, TFileHandle &logfile){
	int state = 0;
	string mesg = "";

	if (currentdist >= endpoint){
		state = 1;
		mesg = "Reached endpoint.";
		sendLog(logfile, time, mesg);
	}
	else if (didDrive){
		if (ultrasonicDist()){
			state = 5;
			mesg = "Ultrasonic triggered";
			sendLog(logfile, time, mesg);
		}
		else {
			state = 0;
			mesg = "Business as usual";
			sendLog(logfile, time, mesg);
		}
	}
	else {
		if (failures > MAXFAIL){
			didDrive = drive(DRIVEDIST, 0, 1, SPEEDHIGH, currentdist, time, logfile);
			if (didDrive) {
				mesg = "Backwards driving worked.";
				sendLog(logfile, time, mesg);
				state = 1;
			}
			else {
				mesg = "Time to tension.";
				sendLog(logfile, time, mesg);
				state = 10;
			}
		}
		else {
			failures++;
			mesg = "HC failures now at: ";
			sendLog(logfile, time, mesg, failures);
		}
	}

	return state;
}
