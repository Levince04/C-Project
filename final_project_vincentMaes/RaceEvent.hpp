
#ifndef RACEEVENT_HPP
#define RACEEVENT_HPP

#include "Car.hpp"
#include <string>

class RaceEvent {
public:
    static void simulateWeatherEvent(Car& car1, Car& car2);
};

#endif