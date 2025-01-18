#include "TemperatureSensor.hpp"
#include <cstdlib>
#include <iostream>

TemperatureSensor::TemperatureSensor(int id) : Sensor(id, "Temperature") {}

void TemperatureSensor::collectData() {
    value = 90.0f + (rand() % 25);  // Température entre 90 et 115
    
    if (value > 110.0f) {
        std::cout << "WARNING: Engine overheating! Temperature: " << value << "°C" << std::endl;
    }
}

void TemperatureSensor::displayData() const {
    std::cout << "Sensor [" << type << "] ID: " << id << ", Value: " << value << "°C";
    if (value > 110.0f) {
        std::cout << " OVERHEAT";
    }
    std::cout << std::endl;
}