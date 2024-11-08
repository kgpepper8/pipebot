//tester.c

#include "tests.c"

const int TEST = 0; //this can be set to anything between 1 and 12, to select which test to run

task main(){
	switch (TEST) {
		case 1: testGetUserDistance();		break;
		case 2: testInitializeSensors();	break;
		case 3: testDrive();							break;
		case 4: testTensionWheels();			break;
		case 5: testClean();							break;
		case 6: testEscape();							break;
		case 7: testShutdown();						break;
		case 8: testCheckSensors();				break;
		case 9: testUltrasonicDist();		break;
		case 10: testHealthCheck();				break;
		case 11: testPrepLog();						break;
		case 12: testSendLog();						break;
		default:
			displayTextLine(10, "Invalid test number.");
			break;
	}
}
