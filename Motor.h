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
    const double slow = 5; //arbitrary movement speed
    const double med = 10; //arbitrary movement speed
    const double fast = 20; //arbitrary movement speed

    double paddleAngleToMotorAngle(double paddleAngle);
};



#endif //MOTOR_H