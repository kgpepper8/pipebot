//tests.c

//includes everything
#include "../src/consts.h"
#include "../src/funcs.h"
#include "../src/startup.c"
#include "../src/tasks.c"
#include "../src/checks.c"
#include "../src/logger.c"

void testGetUserDistance();		//1
void testInitializeSensors();	//2
void testDrive();							//3
void testTensionWheels();			//4
void testClean();							//5
void testEscape();						//6
void testShutdown();					//7
void testUltrasonicDist();		//8
void testHealthCheck();				//9
void testPrepLog();						//10
void testSendLog();						//11

void testThing(); //0

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

void testEscape(){
	float currentdist = 100;
	bool stuck = true;
	int time = 10;

	float initialcurrentdist = currentdist;
	if (stuck)
	{
		escape(currentdist, time);
		if (abs(currentdist - initialcurrentdist) < 3) // can change 3 for other error margin //
			{
				displayString(8, "Robot is stuck and shutdown");
			}
		else
		{
			displayString(8, "Robot escaped being stuck, retry test");
		}
	}
	else if (!stuck)
	{
		escape(currentdist, time);
		if (abs(currentdist - initialcurrentdist) > 3)
		{
			displayString(8, "Robot exited pipe");
		}
		else
		{
			displayString(8, "Robot got stuck, retry test");
		}
	}
}

void testGetUserDistance(){
	displayString(1, "Please set distance to 15 cm");
	wait1Msec(2000);
	float disttest = getUserDistance();
	if ((disttest > 15*CONV-1) && (disttest < 15*CONV+1))
 	{
		displayString(3, "Distance correctly calculated");
	}
	else
	{
		displayString(3, "Error calculating distance");
	}
}

void testShutdown(){
	int pastRotations = 100;
	int time = 10;

	shutdown(pastRotations, time);
	//user presses up button if detensioning is correct//
	while (!getButtonPress(buttonAny)){}

	if (getButtonPress(buttonUp))
	{
		displayString(3, "Shutdown successfull");
	}
	else
	{
		displayString(3, "Shutdown failure");
	}
}

void testInitializeSensors(){
}

void testDrive(){
}

void testTensionWheels(){
}

void testClean(){
}

void testUltrasonicDist(){
}

void testPrepLog(){
}

void testThing(){
	int pastRotations = 360*12;
	int time = 1;
	float currentdist = 100;

	tensionWheels(pastRotations, time);

	drive(10, 1, 1, 100, currentdist, time);
}
