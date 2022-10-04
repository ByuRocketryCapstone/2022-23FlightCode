#include "Motor.h"

Motor::Motor()
{
    currentAngle = 0;
    //FIXME: should we put some code here to make sure the paddles are fully closed at startup?
}


//algorithm for converting desired paddle angle to motor actuation angle
double Motor::paddleAngleToMotorAngle(double paddleAngle)
{
    return 0.0;
}