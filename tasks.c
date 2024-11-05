//tasks.c
#include "logger.c"
#include "checks.c"

//holds the conversion factor for motor encoder count to distance
const float CONV = PI*2.75/180;


//NEED TO WRITE DESCRIPTIVE COMMENTS STILL
void mainLoop(float endpoint, float drivedist);
float drive(float dist, bool direction, bool stop, float &currentdist, int time);
void tensionWheels();
void clean();
void escape();
void shutdown();