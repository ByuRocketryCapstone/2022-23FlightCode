#ifndef MAIN_CPP
#define MAIN_CPP
#include "mainSM.h"
#include <string>
#include <sstream>
using namespace std;

#define LOG_PTR_ARRAY_MAX_SIZE 20


bool armed;
bool ignition;
bool cutoff;
bool apogee;
bool retracted;
bool ground;
bool done;
bool abortControls;
bool reset;
//Logger mainLogger;
int runNumber;
string fileName;
Logger* logPtrArray[20];
int numLogs;

//dynamically allocate logs
bool main_MakeLog(int runNumber) {
    if (runNumber > 20) {
        return false;
    }
    else {
        fileName = "Run_" + to_string(runNumber) + ".txt";
        Logger* loggerPtr = new Logger(fileName);
        logPtrArray[runNumber - 1] = loggerPtr;
        ++numLogs;
        return true;
    }
}

//free heap dynamic logs memory
void main_DeleteLogs(int numLogs) {
    while (numLogs > 0) {
        delete logPtrArray[numLogs - 1];
        --numLogs;
    }
}





static enum brakeControlState {
    init_st, //initialize all global data and functions
    wait_arm_st, //wait on pad for arming
    arm_st, //armed and ready, waiting to detect ignition, maybe take in mission-specific initial conditions
    wait_cutoff_st, //wait for engine cuttoff, all while logging data, jump to update_st
    wait_apogee_st, //detects apogee reached
    retract_st, //retract paddles for safety during descent
    descent_st, //tracK data during descent
    done_st, //all doneeee, close data files, wait for recovery
    abort_st //emergency or manual abort
} CS, NS; // current and next states



void main_Init() {
    armed = false;
    ignition = false;
    cutoff = false;
    apogee = false;
    retracted = false;
    ground = false;
    done = false;
    abortControls = false;
    reset = false;
    numLogs = 0;
    runNumber = 1;
    main_MakeLog(runNumber);
};


void main_Tick() {
    //state update, Mealy actions
    switch (CS) {
    case init_st:
        //initialize variables and functions, proceed to wait_arm_st
        main_Init();
        NS = wait_arm_st;
        break;

    case wait_arm_st:
        //wait for manual arm, then go to arm_st and enable sensors and data logging
        if (!armed) {
            NS = wait_arm_st;
        }
        else {
            NS = arm_st;
            updateData_enable();
            logPtrArray[runNumber - 1]->log_enable(runNumber);
        }
        break;

    case arm_st:
        //wait for ignition detect, then go to wait_cutoff_st
        if (!ignition) {
            NS = arm_st;
        }
        else {
            NS = wait_cutoff_st;
        }
        break;

    case wait_cutoff_st:
        //stay physically dormant for powered portion of flight, then enable hardware control 
        if (!cutoff) {
            NS = wait_cutoff_st;
        }
        else {
            NS = wait_apogee_st;
            hardwareControl_enable();
        }
        break;

    case wait_apogee_st:
        //main state for active controls, wait for apogee
        if (!apogee) {
            NS = wait_apogee_st;
        }
        else {
            NS = retract_st
        }
        break;

    case retract_st:
        //wait for paddles to be retracted, then disable hardwareControl sm
        if (!retracted) {
            NS = retract_st;
        }
        else {
            NS = descent_st;
            hardwareControl_disable();
        }
        break;

    case descent_st:
        //wait to detect touchdown, then start to shut down systems
        if (!ground) {
            NS = descent_st;
        }
        else {
            NS = done_st;
            updateData_disable();
            logPtrArray[runNumber - 1]->log_disable();
        }
        break;

    case done_st:
        //wait for manual reset, then go back to wait_arm_st and reset tracking variables
        if (!reset) {
            NS = done_st;
        }
        //else if (turnoff) {
            ///dont make new logger
        //}
        else {
            NS = wait_arm_st;
            ++runNumber;
            armed = false;
            ignition = false;
            cutoff = false;
            apogee = false;
            retracted = false;
            ground = false;
            done = false;
            abortControls = false;
            reset = false;
            main_MakeLog(runNumber);
        }
        break;

    case abort_st:
        NS = done_st;
        break;

    default:
        break;

    }

    //state action, Moore actions
    switch (CS) {
    case init_st:
        break;

    case wait_arm_st:
        //armed = get button push();
        break;

    case arm_st:
        if (update_getIgnition() == true) {
            ignition = true;
        }
        break;

    case wait_cutoff_st:
        if (update_getCutoff() == true) {
            cutoff = true;
        }
        break;

    //main control functionality
    case wait_apogee_st:
        break;

    case retract_st:
        break;

    case descent_st:
        break;

    case done_st:
        break;

    case abort_st:
        //make sure to have function that logs the error
        updateData_disable();
        logPtrArray[runNumber - 1]->log_disable();
        break;

    default:
        break;

    }

    //update state
    CS = NS;

}



#endif