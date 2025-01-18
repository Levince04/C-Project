#ifndef RACE_STRATEGY_HPP
#define RACE_STRATEGY_HPP

#include <vector>
#include <string>
#include <map>

struct PitStop {
    int lap;
    std::string tyreCompound;
};

class RaceStrategy {
private:
    std::string strategyName;
    std::vector<PitStop> plannedStops;
    std::map<std::string, std::string> weatherContingency;

public:
    RaceStrategy(const std::string& name);
    void addPlannedStop(int lap, const std::string& compound);
    void addWeatherContingency(const std::string& weather, const std::string& tyreChoice);
    std::string getStrategyName() const;
    const std::vector<PitStop>& getPlannedStops() const;
    std::string getTyreForWeather(const std::string& weather) const;
    bool hasPitStopOnLap(int currentLap) const;
    std::string getTyreCompoundForLap(int currentLap) const;
};

class StrategyManager {
private:
    std::vector<RaceStrategy> availableStrategies;

public:
    StrategyManager();
    void initializeStrategies();
    void displayAvailableStrategies() const;
    const RaceStrategy& getStrategy(size_t index) const;
};

#endif
