//tests.c

//includes everything
#include "../src/consts.h"
#include "../src/logger.c"
#include "../src/tasks.c"
#include "../src/checks.c"
#include "../src/startup.c"

void testGetUserDistance();		//1
void testInitializeSensors();	//2
void testDrive();							//3
void testTensionWheels();			//4
void testClean();							//5
void testEscape();						//6
void testShutdown();					//7
void testCheckSensors();			//8
void testUltrasonicDist();		//9
void testHealthCheck();				//10
void testPrepLog();						//11
void testSendLog();						//12

//write all the test functions below this line

void testHealthCheck(){
	float currentdist = 100;
	float enddist = 1000;
	bool accel = true;
	float drivedist = 5;
	int time = 5;

	healthCheck(currentdist, enddist, accel, drivedist, time);
}

void testSendLog(){
	int time = 151;
	float arg = 55.6;
	string teststring = "Message. ";
	sendLog(time, teststring);
	sendLog(time, teststring, arg);
}
