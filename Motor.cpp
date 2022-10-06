#include "Motor.h"
#include <math.h>
#include <stdlib.h>


//constructor
Motor::Motor()
{
    currentAngle = 0;
    //FIXME: should we put some code here to make sure the paddles are fully closed at startup?
};

//algorithm for converting desired paddle angle to motor actuation angle
// returns instruction for motor
double Motor::paddleAngleToMotorAngle(double paddleAngle)
{
    double rotations = 0.0;
    //calculations
    return rotations;
};

//determines if and what direction motor needs to move and sends instructions to motor
void Motor::moveMotor(double paddleAngle) {
    if (Motor.currentAngle == this(paddleAngle)) {
        return;
    }
    else {
        double speed;
        double diffAngle = paddleAngle - currentAngle;
        if (diffAngle < 5) {
            speed = slow;
        }
        else if (diffAngle <= 10) {
            speed = med;
        }
        else {
            speed = fast;
        }
        double motorRotations = Motor::paddleAngleToMotorAngle(diffAngle);
        // motor.step(motorRotations, speed);
    }
    //if no closed-loop rotation feedback
    currentAngle = paddleAngle;
    return;
};

