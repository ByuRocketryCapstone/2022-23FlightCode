#ifndef MAIN_CPP
#define MAIN_CPP
#include "mainSM.h"








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
    descent_st, //tracK data during descent
    done_st, //all doneeee, close data files, wait for recovery
} CurrState, NextState;






mainTick() {
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



#endif