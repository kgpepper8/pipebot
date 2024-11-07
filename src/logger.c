//logger.c
#include "fileLib/PC_FileIO.c"

//holds the desired name of the logfile
const string LOGNAME = "log.txt";

/* function implementations below this line ----------------------------------- */

void sendLog(int time, string msg){
	char message[100] = "";


	strcat(message, time);
	strcat(message, "\t");
	strcat(message, msg);

	writeTextPC(prepLog(), message);
	writeEndlPC();
}
