#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <vector>
#include <memory>
#include "Sensor.hpp"
#include "Tyre.hpp"
#include "Weather.hpp"
#include "RaceStrategy.hpp"

class Car {
private:
    int carId;
    std::string driverName;
    std::vector<std::shared_ptr<Sensor>> sensors;
    std::unique_ptr<Tyre> currentTyre;
    int lapsSinceLastPit;
    int totalPitStops;

public:
    Car(int id, const std::string& driverName);
    ~Car();
    void addSensor(std::shared_ptr<Sensor> sensor);
    void collectAndDisplayData() const;
    std::string getDriverName() const;
    void updateSensors(int currentLap);  // Remplace updateLap
    void changeTyres(const std::string& compound) {
        currentTyre = std::make_unique<Tyre>(compound);
        lapsSinceLastPit = 0;
        totalPitStops++;
    }
    void updateTyreCondition(bool isRaining) {
        if (currentTyre) {
            currentTyre->degrade(isRaining);
            lapsSinceLastPit++;
        }
    }
    bool needsPitStop() const {
        return currentTyre && currentTyre->needsPitStop();
    }

    // Getters pour l'état des pneus
    std::string getCurrentTyreCompound() const { return currentTyre ? currentTyre->getCompound() : "None"; }
    int getTyreCondition() const { return currentTyre ? currentTyre->getCondition() : 0; }
    int getLapsSinceLastPit() const { return lapsSinceLastPit; }
    int getTotalPitStops() const { return totalPitStops; }
};

#endif