#ifndef SPEEDSENSOR_HPP
#define SPEEDSENSOR_HPP

#include "Sensor.hpp"

class SpeedSensor : public Sensor {
private:
    int currentLap;  

public:
    SpeedSensor(int id);
    void collectData() override;
    void displayData() const override;
    void setCurrentLap(int lap);  
};

#endif