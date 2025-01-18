#include "FuelSensor.hpp"
#include <iostream>
#include <cstdlib>

FuelSensor::FuelSensor(int id) : Sensor(id, "Fuel"), fuelLevel(100.0f), consumptionRate(2.0f) {}

void FuelSensor::collectData() {
    value = fuelLevel;
}

void FuelSensor::displayData() const {
    std::cout << "Sensor [" << type << "] ID: " << id << ", Level: " << value << "%";
    if (value < 20.0f) {
        std::cout << " LOW FUEL WARNING";
    }
    std::cout << std::endl;
}

void FuelSensor::updateFuelLevel(int currentLap) {
    // Réduire le niveau de carburant en fonction du tour
    fuelLevel = std::max(0.0f, 100.0f - (currentLap * consumptionRate));
}