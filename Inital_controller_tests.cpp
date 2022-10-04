#include <string>
#include <iostream>
#include <cmath>
#include "Logger.h"
#include "SensorData.h"

using namespace std;

Logger logger;

double targetAlt;
double PredictedAlt;
double Fd;
double M;
double rho;
double Cd; // rocket Cd (this will actually be take from open rocket but for now lets assume is constant)
double A; // frontal rocket area 
double Ke;
double Pe;


int main(int argc, char* argv[])
{
    SensorData SD(0,0,0,0,0);

// Begin predicted trajectroy calulations post engine cut off

while (SD.getHeight() >=  6000 && SD.getHeight() < 9500) {

//predict an intial height assuming the air brakes did not deploy ie an inital reference height 

PredictedAlt = 0;





}





  
}