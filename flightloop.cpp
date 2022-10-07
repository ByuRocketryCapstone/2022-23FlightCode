#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Motor.h"
#include "Parameters.h"
#include "SensorData.h"
#include "SimTable.h"
#include "Logger.h"

using namespace std;

Logger logger;



int main(int argc, char* argv[])
{
    cout << "Hello World!" << endl;
    cout << "We've been trying to reach you about your car's extended warranty." << endl;
    cout << "I would like to speak to your manager..." << endl;

    CurrState = init_st;
    NextState = init_st;
    

    //start state machine
    while (1) {
        mainTick();
     
    }
}
