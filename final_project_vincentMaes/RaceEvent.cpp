
#include "RaceEvent.hpp"
#include <iostream>
#include <cstdlib>

void RaceEvent::simulateWeatherEvent(Car& car1, Car& car2) {
    int event = rand() % 3;
    std::string message;
    
    switch (event) {
        case 0:
            message = "Rain affecting both cars' telemetry.";
            break;
        case 1:
            message = "Heat wave affecting both cars' temperature readings.";
            break;
        case 2:
            message = "No significant weather changes.";
            break;
    }
    std::cout << message << std::endl;
}
