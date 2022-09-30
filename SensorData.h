#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

class SensorData
{
    public:
    SensorData(double height, 
                double velocity, 
                double acceleration, 
                double pitchAngle,
                double timestamp);
    double getHeight();
    double getVelocity();
    double getAcceleration();
    double getPitchAngle();
    double getTimestamp();

    private:
    double height;          // m
    double velocity;        // m/s
    double acceleration;    // m/s^2
    double pitchAngle;      // degrees
    double timestamp;       // s

};

#endif //SENSOR_DATA_H