#include "HardwareControl.h"
#include "SensorData.h"



static bool enable;
static bool acting;

static enum hardwareControlState {
	init_st,
	wait_enable_st,
	start_act_st,
	wait_act_st,
	done_st
}CurrState, NextState;

// initialize
void hardwareControl_init() {
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
	//state update
	switch (CurrState) {
	case init_st:
		NextState = wait_enable_st;
		break;

	case wait_enable_st:
		if (!enable) {
			NextState = wait_enable_st;
		}
		else if (enable) {
			NextState = start_act_st;
		}
		break;

	case start_act_st:
		NextState = wait_act_st;
		break;

	case wait_act_st:
		if (acting) {
			NextState = wait_act_st;
		}
		else if (!acting) {
			NextState = done_st;
		}
		break;

	case done_st:
		if (!enable) {
			NextState = wait_enable_st;
		}
		else if (enable) {
			NextState = done_st;
		}
		break;
	}

	//state action
	switch (CurrState) {
	case init_st:
		hardwareControl_init();
		break;

	case wait_enable_st:
		break;

	case start_act_st:
		break;

	case wait_act_st:
		break;

	case done_st:
		break;
	}

	CurrState = NextState;
};