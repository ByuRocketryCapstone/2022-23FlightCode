#include <string>
#include <iostream>
#include <cmath>
#include "Logger.h"
#include "SensorData.h"
#include "Parameters.h"
#include "SimTable.h"

using namespace std;

extern Logger logger;

double Alterror;
double PredictedAlt;
double TARGET_HEIGHT; // just a place holder for now 
double Accerror;
int state = 1;

int main(int argc, char* argv[])
{
    SensorData SD(0,0,0,0,0);
    Consts CV();

// Begin predicted trajectroy calulations post engine cut off

switch (state)
{
case 1: // Case 1 is pre-engine cut off
    /* code */
    // This state is essentially telling the paddles to remain closed untill post engine cut off




    break;

case 2: // Case 2 is post cut off

while (SD.getHeight() >=  6000 && SD.getHeight() < TARGET_HEIGHT-500) {

//predict an intial height assuming the air brakes did not deploy ie an inital reference height 

PredictedAlt = (pow(SD.getVelocity(),2))/(SD.getAcceleration()) + SD.getHeight();// this is the predicted height by kinematics based on the current inputs of the rocket
 
//Compare Predicted Alt to Target Alt
//Alterror = TARGET_HEIGHT - PredictedAlt; 
//Accerror = IdealAcc@given_timestep - SD.getAccerlation
//Verror = IdealV@Given_timestep - SD.getVelcotiy 
// if (Alterror && Accerror || Alterror && Verror || Alterror && Verror && Accerror > 0) {
//  code that would actuate paddles 
// }
// else if ()
}

state = 3;
break;

case 3: //back up case incase we need to full brake to attempt to reach target height

//Code essentially tells brakes to max deploy to try and hit target height if case 2 was not completly sucessful

break;


default:
    break;

}
return 0;
}
