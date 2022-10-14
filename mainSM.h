#ifndef MAINSM_H
#define MAINSM_H
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include "Logger.h"
#include "Motor.h"
#include "Parameters.h"
#include "SensorData.h"
#include "SimTable.h"
#include "Calculations.h"
#include "HardwareControl.h"
#include "UpdateData.h"


//isr tick function
void main_Tick();

//main initialization function
void main_Init();

void updateEnable();
//void logEnable();
//void hardwarecontrols_enable();
bool update_getIgnition();
bool update_getCutoff();


#endif
