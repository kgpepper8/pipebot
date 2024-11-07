//tests.c

//includes everything so it can be tested
#include "../src/startup.h"
#include "../src/tasks.h"
#include "../src/checks.h"
#include "../src/logger.h"

void testGetUserDistance();		//1
void testInitializeSensors();	//2
void testMainLoop();			//3
void testDrive();				//4
void testTensionWheels();		//5
void testClean();				//6
void testEscape();				//7
void testShutdown();			//8
void testCheckSensors();		//9
void testHealthCheck();			//10
void testPrepLog();				//11
void testSendLog;				//12

//write all the test functions below this line