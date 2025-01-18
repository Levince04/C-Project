#include "Sensor.hpp"
#include <iostream>

Sensor::Sensor(int id, const std::string& type) : id(id), type(type), value(0.0f) {}

Sensor::~Sensor() {
    std::cout << "Cleaning up Sensor [" << type << "] ID: " << id << std::endl;
}

void Sensor::displayData() const {
    std::cout << "Sensor [" << type << "] ID: " << id << ", Value: " << value;
    if (type == "Speed (km/h)") {
        std::cout << " km/h";
    } else if (type == "Temperature") {
        std::cout << " °C";
    }
    std::cout << std::endl;
}