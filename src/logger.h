//logger.h

#ifndef LOGGER
	#define LOGGER
	#include "logger.c"
#endif

/*
Author: Samuel Mailhot
No parameters.
Creates or opens, then returns, a logfile with the proper name.
*/
TFileHandle prepLog();

/*
Author: Kiran Ghanekar
Parameters: int time (the log's timestamp), string msg (the message to be written)
No returns. Writes a log message to the file returned by prepLog().
*/
void sendLog(int time, string msg);