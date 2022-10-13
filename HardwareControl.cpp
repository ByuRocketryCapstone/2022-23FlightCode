#include "HardwareControl.h"
#include "SensorData.h"



static bool enable;

static enum hardwareControlState {
	init_st,
	wait_enable_st,
	start_act_st,
	wait_act_st,
	done_st
}CurrState, NextState;

// initialize
void hardwareConrol_init() {
	enable = false;
};

//enable SM
void hardwareControl_enable() {
	enable = true;
};

//disable SM
void hardwareControl_disable() {
	enable = false;
};

//state machine
void hardwareControl_tick() {


};