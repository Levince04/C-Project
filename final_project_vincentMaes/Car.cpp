// Car.cpp
#include "Car.hpp"
#include "SpeedSensor.hpp"  // Ajout de cet include
#include <iostream>
#include "FuelSensor.hpp"  // Ajoutez ceci au début de Car.cpp


Car::Car(int id, const std::string& driverName) : carId(id), driverName(driverName) {}

Car::~Car() {
    std::cout << "Cleaning up car ID " << carId << " driven by " << driverName << std::endl;
}

void Car::addSensor(std::shared_ptr<Sensor> sensor) {
    sensors.push_back(sensor);
}


void Car::updateSensors(int currentLap) {
    for (auto& sensor : sensors) {
        if (auto* speedSensor = dynamic_cast<SpeedSensor*>(sensor.get())) {
            speedSensor->setCurrentLap(currentLap);
        }
        else if (auto* fuelSensor = dynamic_cast<FuelSensor*>(sensor.get())) {
            fuelSensor->updateFuelLevel(currentLap);
        }
    }
}

void Car::collectAndDisplayData() const {
    std::cout << "\nTelemetry for Car ID " << carId << " driven by " << driverName << ":" << std::endl;
    for (const auto& sensor : sensors) {
        sensor->collectData();
        sensor->displayData();
    }
}

std::string Car::getDriverName() const {
    return driverName;
}