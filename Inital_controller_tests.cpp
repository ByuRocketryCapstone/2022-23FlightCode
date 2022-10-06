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

int main(int argc, char* argv[])
{
    SensorData SD(0,0,0,0,0);
    Consts CV();

// Begin predicted trajectroy calulations post engine cut off

while (SD.getHeight() >=  6000 && SD.getHeight() < 9500) {

//predict an intial height assuming the air brakes did not deploy ie an inital reference height 

PredictedAlt = (pow(SD.getVelocity(),2))/(SD.getAcceleration()) + SD.getHeight();// this is the predicted height by kinematics based on the current inputs of the rocket

//Compare Predicted Alt to Target Alt
//Alterror = TARGET_HEIGHT - PredictedAlt; 
//Accerror = IdealAcc@given_timestep - SD.getAccerlation
//Verror = IdealV@Given_timestep - SD.getVelcotiy 
// if Alterror && Accerror && Verror > 0 {
//  code that would actuate




}
return 0;
}
