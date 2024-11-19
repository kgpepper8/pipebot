//tester.c

//#include "tests.c"
#include "../src/consts.h"
#include "../src/funcs.h"
#include "../src/startup.c"
#include "../src/tasks.c"
#include "../src/checks.c"
#include "../src/logger.c"

const int TEST = 100; //this can be set to anything between 1 and 11, to select which test to run
void testThing(){
	setSoundVolume(100);
	playSoundFile("Robotexitnoise.mp3");

	int pastRotations = 360*12*10000;
	int time = 1;
	float currentdist = 100;

	tensionWheels(pastRotations, 1);

	motor[LDSCREW] = 100;
}

task main(){
	testThing();
	/*
	switch (TEST) {
		case 0: testThing(); 							break;
		case 1: testGetUserDistance();		break;
		case 2: testInitializeSensors();	break;
		case 3: testDrive();							break;
		case 4: testTensionWheels();			break;
		case 5: testClean();							break;
		case 6: testEscape();							break;
		case 7: testShutdown();						break;
		case 8: testUltrasonicDist();			break;
		case 9: testHealthCheck();				break;
		case 10: testPrepLog();						break;
		case 11: testSendLog();						break;
	}
	*/
}
