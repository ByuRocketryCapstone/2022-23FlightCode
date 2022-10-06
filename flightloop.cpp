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

static enum brakeControlState {
    init_st, //initialize all global data and functions
    wait_arm_st, //wait on pad for arming
    arm_st, //armed and ready, waiting to detect ignition, maybe take in mission-specific initial conditions
    ignition_st, //detected ignition
    wait_cutoff_st, //wait for engine cuttoff, all while logging data, maybe jump to 
    update_st, //refresh current sensor data, maybe jump to log_st
    control_st, //calculate and compare desired values and implement paddle actuation
    log_st, //log data, sensor data and motor movements
    at_apogee_st, //detects apogee reached
    retract_st, //retract paddles for safety during descent
    descent_st, //tract data during descent
    done_st, //all doneeee, close data files, wait for recovery
} CurrState, NextState;

int main(int argc, char* argv[])
{
    cout << "Hello World!" << endl;
    cout << "We've been trying to reach you about your car's extended warranty." << endl;
    cout << "I would like to speak to your manager..." << endl;

    CurrState = init_st;
    NextState = init_st;
    

    //start state machine
    while (1) {

        //state update, Mealy actions
        switch (CurrState) {
        case init_st:
            break;

        case wait_arm_st:
            break;

        case arm_st:
            break;

        case ignition_st:
            break;

        case wait_cutoff_st:
            break;

        case update_st:
            break;

        case control_st:
            break;

        case log_st:
            break;

        case at_apogee_st:
            break;

        case retract_st:
            break;

        case descent_st:
            break;

        case done_st:
            break;

        default:
            break;

        }

        //update state
        CurrState = NextState;

        //state action, Moore actions
        switch (CurrState) {
        case init_st:
            break;

        case wait_arm_st:
            break;

        case arm_st:
            break;

        case ignition_st:
            break;

        case wait_cutoff_st:
            break;

        case update_st:
            break;

        case control_st:
            break;

        case log_st:
            break;

        case at_apogee_st:
            break;

        case retract_st:
            break;

        case descent_st:
            break;

        case done_st:
            break;

        default:
            break;

        }
    }
}
