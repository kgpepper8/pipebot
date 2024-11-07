//tests.c

//including startup and tasks includes everything by extension
#include "../src/startup.c"
#include "../src/tasks.c"

void testGetUserDistance();		//1
void testInitializeSensors();	//2
void testMainLoop();			//3
void testDrive();				//4
void testTensionWheels();		//5
void testClean();				//6
void testEscape();				//7
void testShutdown();			//8
void testCheckSensors();		//9
void testUltrasonicDist();		//10
void testHealthCheck();			//11
void testPrepLog();				//12
void testSendLog;				//13

//write all the test functions below this line