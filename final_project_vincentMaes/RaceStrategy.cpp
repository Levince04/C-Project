#include "RaceStrategy.hpp"
#include <iostream>
#include <stdexcept>

RaceStrategy::RaceStrategy(const std::string& name) : strategyName(name) {}

void RaceStrategy::addPlannedStop(int lap, const std::string& compound) {
    plannedStops.push_back({lap, compound});
}

void RaceStrategy::addWeatherContingency(const std::string& weather, const std::string& tyreChoice) {
    weatherContingency[weather] = tyreChoice;
}

std::string RaceStrategy::getStrategyName() const {
    return strategyName;
}

const std::vector<PitStop>& RaceStrategy::getPlannedStops() const {
    return plannedStops;
}

std::string RaceStrategy::getTyreForWeather(const std::string& weather) const {
    auto it = weatherContingency.find(weather);
    return (it != weatherContingency.end()) ? it->second : "Medium";
}

bool RaceStrategy::hasPitStopOnLap(int currentLap) const {
    for (const auto& stop : plannedStops) {
        if (stop.lap == currentLap) return true;
    }
    return false;
}

std::string RaceStrategy::getTyreCompoundForLap(int currentLap) const {
    for (const auto& stop : plannedStops) {
        if (stop.lap == currentLap) return stop.tyreCompound;
    }
    return "";
}

StrategyManager::StrategyManager() {
    initializeStrategies();
}

void StrategyManager::initializeStrategies() {
    // Stratégie Agressive
    RaceStrategy aggressive("Aggressive - Two stops");
    aggressive.addPlannedStop(1, "Soft");
    aggressive.addPlannedStop(15, "Medium");
    aggressive.addPlannedStop(30, "Soft");
    aggressive.addWeatherContingency("LIGHT_RAIN", "Intermediate");
    aggressive.addWeatherContingency("HEAVY_RAIN", "Wet");
    availableStrategies.push_back(aggressive);

    // Stratégie Conservative
    RaceStrategy conservative("Conservative - One stop");
    conservative.addPlannedStop(1, "Medium");
    conservative.addPlannedStop(25, "Hard");
    conservative.addWeatherContingency("LIGHT_RAIN", "Intermediate");
    conservative.addWeatherContingency("HEAVY_RAIN", "Wet");
    availableStrategies.push_back(conservative);

    // Stratégie Mixte
    RaceStrategy mixed("Mixte - Flexible");
    mixed.addPlannedStop(1, "Medium");
    mixed.addPlannedStop(20, "Soft");
    mixed.addPlannedStop(35, "Medium");
    mixed.addWeatherContingency("LIGHT_RAIN", "Intermediate");
    mixed.addWeatherContingency("HEAVY_RAIN", "Wet");
    availableStrategies.push_back(mixed);
}

void StrategyManager::displayAvailableStrategies() const {
    std::cout << "\nAvailable Strategies :\n";
    for (size_t i = 0; i < availableStrategies.size(); i++) {
        std::cout << i + 1 << ". " << availableStrategies[i].getStrategyName() << "\n";
        std::cout << "   Planned Pit stops :\n";
        for (const auto& stop : availableStrategies[i].getPlannedStops()) {
            if (stop.lap == 1) {
                std::cout << "   - Starting compound : " << stop.tyreCompound << "\n";
            } else {
                std::cout << "   - Lap " << stop.lap << " : " << stop.tyreCompound << "\n";
            }
        }
        std::cout << "\n";
    }
}

const RaceStrategy& StrategyManager::getStrategy(size_t index) const {
    if (index >= availableStrategies.size()) {
        throw std::out_of_range("Strategy unavailable");
    }
    return availableStrategies[index];
}