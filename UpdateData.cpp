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
void updateData_tick();


