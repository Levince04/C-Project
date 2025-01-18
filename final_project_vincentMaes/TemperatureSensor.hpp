#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP

#include "Sensor.hpp"

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int id);

    void collectData();
    void displayData() const; // Ajoutez 'const' ici
};

#endif // TEMPERATURESENSOR_HPP
