//tester.c

#include "tests.c"

const int TEST = 0; //this can be set to anything between 1 and 13, to select which test to run

task main(){
	switch (TEST) {
		case 1: testGetUserDistance();		break;
		case 2: testInitializeSensors();	break;
		case 3: testMainLoop();				break;
		case 4: testDrive();				break;
		case 5: testTensionWheels();		break;
		case 6: testClean();				break;
		case 7: testEscape();				break;
		case 8: testShutdown();				break;
		case 9: testCheckSensors();			break;
		case 10: testCheckUltrasonicDist();	break;
		case 11: testHealthCheck();			break;
		case 12: testPrepLog();				break;
		case 13: testSendLog();				break;
		default:
			displayTextLine(10, "Invalid test number.");
			break;
	}
}