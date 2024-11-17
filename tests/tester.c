//tester.c

#include "tests.c"

const int TEST = 0; //this can be set to anything between 1 and 11, to select which test to run

task main(){
	switch (TEST) {
		case 0: testThing(); break;

		case 1: testGetUserDistance();		break;
		case 2: testInitializeSensors();	break;
		case 3: testDrive();							break;
		case 4: testTensionWheels();			break;
		case 5: testClean();							break;
		case 6: testEscape();							break;
		case 7: testShutdown();						break;
		case 8: testUltrasonicDist();		break;
		case 9: testHealthCheck();				break;
		case 10: testPrepLog();						break;
		case 11: testSendLog();						break;
		default:
			displayTextLine(10, "Invalid test number.");
			break;
	}
}
