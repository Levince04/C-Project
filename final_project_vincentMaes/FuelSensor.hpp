#ifndef FUELSENSOR_HPP
#define FUELSENSOR_HPP

#include "Sensor.hpp"

class FuelSensor : public Sensor {
private:
    float fuelLevel;  // Niveau de carburant en pourcentage
    float consumptionRate;  // Taux de consommation par tour

public:
    FuelSensor(int id);
    void collectData() override;
    void displayData() const override;
    void updateFuelLevel(int currentLap);
};

#endif