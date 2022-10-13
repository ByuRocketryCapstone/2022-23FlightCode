#ifndef MAIN_CPP
#define MAIN_CPP
#include "mainSM.h"



static bool armed;
static bool ignition;
static bool cutoff;
static bool apogee;
static bool retract;
static bool ground;
static bool done;





static enum brakeControlState {
    init_st, //initialize all global data and functions
    wait_arm_st, //wait on pad for arming
    arm_st, //armed and ready, waiting to detect ignition, maybe take in mission-specific initial conditions
    //ignition_st, //detected ignition
    wait_cutoff_st, //wait for engine cuttoff, all while logging data, jump to update_st 
    //update_st, //refresh current sensor data, maybe jump to log_st
    //control_st, //calculate and compare desired values and implement paddle actuation
    //log_st, //log data, sensor data and motor movements
    wait_apogee_st, //detects apogee reached
    retract_st, //retract paddles for safety during descent
    descent_st, //tracK data during descent
    done_st, //all doneeee, close data files, wait for recovery
} CS, NS;



void mainInit() {
    armed = false;
    ignition = false;
    cutoff = false;
    apogee = false;
    ground = false;
    done = false;
};


void main_Tick() {
    //state update, Mealy actions
    switch (CS) {
    case init_st:
        mainInit();
        NS = wait_arm_st;
        break;

    case wait_arm_st:
        if (!armed) {
            NS = wait_arm_st;
        }
        else {
            NS = arm_st;
            updateEnable();
            logEnable();
        }
        break;

    case arm_st:
        if (!ignition) {
            NS = arm_st;
        }
        else {
            NS = wait_cutoff_st;
        }
        break;

    //case ignition_st:
    //    break;

    case wait_cutoff_st:
        if (!cutoff) {
            NS = wait_cutoff_st;
        }
        else {
            NS = wait_apogee_st;
            hardwarecontrols_enable();
        }
        break;

    case update_st:
        break;

    case control_st:
        break;

    case log_st:
        break;

    case wait_apogee_st:
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

    //state action, Moore actions
    switch (CS) {
    case init_st:
        break;

    case wait_arm_st:
        break;

    case arm_st:
        if (update_getIginition() == true) {
            ignition = true;
        }
        break;

    //case ignition_st:
    //    break;

    case wait_cutoff_st:
        if (update_getCutoff() == true) {
            cutoff = true;
        }
        break;

    case update_st:
        break;

    case control_st:
        break;

    case log_st:
        break;

    case wait_apogee_st:
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
    CS = NS;

}



#endif