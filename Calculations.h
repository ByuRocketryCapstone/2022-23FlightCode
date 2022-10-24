#ifndef CALCULATIONS_H
#define CALCULATIONS_H




//deterimine if at apogee, sets apogee flag
bool calcAtAppogee(int accel, int vel);

//determine instance of ignition, sets ignition flag
bool calcIgnintion(int accel, int vel, int height);

//determine main engine cutoff, sets MECO flag
bool calcMECO(int accel, int vel, int height);

//determine if hits ground, sets ground flag
bool calcOnGround(int accel, int vel, int height);

//determine error in acceleration vs. desired acceleration at current time stamp relative to MECO
int calcAccelError(int accel, int desiredAccel, int timeRefMeco);

//determine error in velocity vs. desired velocity at current time stamp relative to MECO
int calcVelError(int vel, int desiredVel, int timeRefMeco);

//determine error in height vs. desired hieght at current time stamp relative to MECO
int calcHeightError(int height, int desiredHeight, int timeRefMeco);

//determine desired new paddle angle given error in kinematics and flight region
int calcNewPaddleAngle(int accelError, int currPaddleAngle, int flightRegion);

//return current paddle angle given motor angle
int getCurrPaddleAngle(int motorAngle);

//determine flight region given speed and height
int calcFlightRegion(int velocity, int height);



#endif