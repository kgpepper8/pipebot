//logger.c
#include "libFile/PC_FileIO.c"

//holds the desired name of the logfile
const string LOGNAME = "log.txt";

/*
No parameters.
Creates or opens, then returns, a logfile with the proper name.
*/
TFileHandle prepLog();

/*
Parameters: int time (the log's timestamp), string msg (the message to be written)
No returns. Writes a log message to the file returned by prepLog().
*/
void sendLog(int time, string msg);