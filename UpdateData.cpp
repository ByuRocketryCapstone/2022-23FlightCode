#include "UpdateData.h"
#include "SensorData.h"



static bool enable;

//state machine states
static enum updateDataState {
	init_st,
	wait_enable_st,
	poll_data_st
}CurrState, NextState;

//initialize
void updateData_init() {
	enable = false;
};

//enable
void updateData_enable() {
	enable = true;
};

//disable
void updateData_disable() {
	enable = false;
};

//state machine tick
void updateData_tick() {
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
			NextState = poll_data_st;
		}
		break;

	case poll_data_st:
		NextState = wait_enable_st;
		break;
	}

	//state action
	switch (CurrState) {
	case init_st:
		updateData_init();
		break;
		
	case wait_enable_st:
		break;

	case poll_data_st:
		break;
	}

	//state advancement 
	CurrState = NextState;
};


