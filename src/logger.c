//logger.c

TFileHandle prepLog() {
	TFileHandle fout;
	openWritePC(fout, "log.txt");
	return fout;
}


void sendLog(int time, string mesg){
	TFileHandle logfile = prepLog();

	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeEndlPC(logfile);
}

void sendLog(int time, string mesg, float &numarg){
	TFileHandle logfile = prepLog();

	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeTextPC(logfile, "\t");
	writeFloatPC(logfile, numarg);
	writeEndlPC(logfile);
}
