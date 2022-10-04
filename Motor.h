#ifndef MOTOR_H
#define MOTOR_H

/*
Class to control all things associated with the stepper motor on the lead screw.
*/

#include "Logger.h"

extern Logger logger;

class Motor
{
    public:
    Motor();
    void moveMotor(double paddleAngle);

    private:
    double currentAngle;        //degrees
    const double LEAD_SCREW_PITCH = 1.0;    //replace with actual pitch

    double paddleAngleToMotorAngle(double paddleAngle);
};

#endif //MOTOR_H