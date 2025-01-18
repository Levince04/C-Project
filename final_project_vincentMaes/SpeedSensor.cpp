#include "SpeedSensor.hpp"
#include <cstdlib>
#include <iostream>

SpeedSensor::SpeedSensor(int id) : Sensor(id, "Speed"), currentLap(1) {}

void SpeedSensor::collectData() {
    value = 280.0f + (rand() % 61);
}

void SpeedSensor::displayData() const {
    std::cout << "Sensor [" << type << "] ID: " << id << ", Value: " << value << " km/h";
    if (value > 320.0f && currentLap >= 3) {  // DRS disponible à partir du tour 3
        std::cout << " DRS Activated";
    }
    std::cout << std::endl;
}

void SpeedSensor::setCurrentLap(int lap) {
    currentLap = lap;
}