//logger.c

TFileHandle prepLog() {
	TFileHandle fout;
	openWritePC(fout, "log.txt");
	return fout;
}


void sendLog(TFileHandle logfile, int time, string mesg){
	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeEndlPC(logfile);
}

void sendLog(TFileHandle logfile, int time, string mesg, float &numarg){
	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeTextPC(logfile, "\t");
	writeFloatPC(logfile, numarg);
	writeEndlPC(logfile);
}

void sendLog(TFileHandle logfile, int time, string mesg, int &numarg){
	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeTextPC(logfile, "\t");
	writeLongPC(logfile, numarg);
	writeEndlPC(logfile);
}
