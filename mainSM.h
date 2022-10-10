#ifndef MAINSM_H
#define MAINSM_H
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include "Logger.h"
#include "Motor.h"
#include "Parameters.h"
#include "SensorData.h"
#include "SimTable.h"
#include "Calculations.h"


//isr tick function
void mainTick();

//main initi
void mainInit();


#endif
