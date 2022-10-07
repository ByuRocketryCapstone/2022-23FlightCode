#ifndef MAIN_SM_H
#define MAIN_SM_H
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "Logger.h"
#include "Motor.h"
#include "Parameters.h"
#include "SensorData.h"
#include "SimTable.h"
#include "Calculations.h"



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

void mainTick();


#endif
