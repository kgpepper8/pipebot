//logger.c

#include "fileLib/PC_FileIO.c"

//holds the desired name of the logfile
const string LOGNAME = "log.txt";

/*
Author: Samuel Mailhot
No parameters.
Creates or opens, then returns, a logfile with the proper name.
*/
TFileHandle prepLog();

/*
Author: Kiran Ghanekar
Parameters: int time (the log's timestamp)
						string msg (the message to be written)
						(optional) float numarg (a numerical thing to log, may or may not be needed)
No returns. Writes a log message to the file returned by prepLog().
*/
void sendLog(int time, string &mesg);
void sendLog(int time, string &mesg, float &numarg);

/* function implementations below this line ----------------------------------- */

TFileHandle prepLog(){

}

void sendLog(int time, string &mesg){
	TFileHandle logfile = prepLog();

	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeEndlPC(logfile);
}

void sendLog(int time, string &mesg, float &numarg){
	TFileHandle logfile = prepLog();

	writeLongPC(logfile, time);
	writeTextPC(logfile, "\t");
	writeTextPC(logfile, mesg);
	writeTextPC(logfile, "\t");
	writeFloatPC(logfile, numarg);
	writeEndlPC(logfile);
}
