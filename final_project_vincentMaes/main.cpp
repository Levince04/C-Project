#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include "Car.hpp"
#include "RaceEvent.hpp"
#include "SpeedSensor.hpp"
#include "TemperatureSensor.hpp"
#include "FuelSensor.hpp"
#include "Tyre.hpp"
#include "Weather.hpp"
#include "RaceStrategy.hpp"

Weather getInitialWeather() {
    int choice;
    std::cout << "\nChoose the initial weather condition :\n";
    std::cout << "1. Dry\n";
    std::cout << "2. Light Rain\n";
    std::cout << "3. Heavy Rain\n";
    std::cout << "Your Choice : ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Weather::DRY;
        case 2: return Weather::LIGHT_RAIN;
        case 3: return Weather::HEAVY_RAIN;
        default: return Weather::DRY;
    }
}

std::string chooseTyreCompound(bool isRaining) {
    int choice;
    std::cout << "\nChoose the Tyres compound :\n";
    if (isRaining) {
        std::cout << "1. Wet\n";
        std::cout << "2. Intermediate\n";
    } else {
        std::cout << "1. Softs\n";
        std::cout << "2. Médiums\n";
        std::cout << "3. Hards\n";
    }
    std::cout << "Your Choice : ";
    std::cin >> choice;

    if (isRaining) {
        return (choice == 1) ? "Wet" : "Intermediate";
    } else {
        switch (choice) {
            case 1: return "Soft";
            case 2: return "Medium";
            case 3: return "Hard";
            default: return "Medium";
        }
    }
}


void initializeRace(Car& car, const std::string& driverName, const RaceStrategy& strategy, bool isRaining) {
    std::cout << "\nInitializing strategy for " << driverName << std::endl;
    std::cout << "Strategy choice: " << strategy.getStrategyName() << std::endl;
    
    // Appliquer les pneus de départ
    std::string initialTyre;
    if (isRaining) {
        initialTyre = strategy.getTyreForWeather(isRaining ? "HEAVY_RAIN" : "DRY");
    } else {
        initialTyre = strategy.getTyreCompoundForLap(1);
    }
    
    car.changeTyres(initialTyre);
    std::cout << "Start compound : " << initialTyre << std::endl;
}

void simulateRace(Car& car1, Car& car2, int totalLaps) {
    // Initialisation de la météo
    WeatherCondition weather(getInitialWeather());
    bool isRaining = weather.isRaining();
    
    // Gestionnaire de stratégies
    StrategyManager strategyManager;
    strategyManager.displayAvailableStrategies();
    
    // Choix des stratégies
    int strategy1, strategy2;
    std::cout << "\nChoose strategy for " << car1.getDriverName() << " (1-3): ";
    std::cin >> strategy1;
    std::cout << "Choose strategy " << car2.getDriverName() << " (1-3): ";
    std::cin >> strategy2;
    
    const RaceStrategy& strat1 = strategyManager.getStrategy(strategy1 - 1);
    const RaceStrategy& strat2 = strategyManager.getStrategy(strategy2 - 1);
    
    // Initialisation des voitures avec leurs stratégies
    initializeRace(car1, car1.getDriverName(), strat1, isRaining);
    initializeRace(car2, car2.getDriverName(), strat2, isRaining);

    // Simulation de la course
    for (int currentLap = 1; currentLap <= totalLaps; currentLap++) {
        std::cout << "\n=== Lap " << currentLap << " ===\n";
        std::cout << "Conditions : " << weather.getWeatherString() << std::endl;

        // Mise à jour des voitures
        car1.updateSensors(currentLap);
        car2.updateSensors(currentLap);
        car1.updateTyreCondition(isRaining);
        car2.updateTyreCondition(isRaining);

        // Vérification des arrêts planifiés pour la voiture 1
        if (strat1.hasPitStopOnLap(currentLap) && currentLap > 1) {
            std::cout << "\nPit stop planned for " << car1.getDriverName() << std::endl;
            std::string newTyre = isRaining ? 
                strat1.getTyreForWeather(weather.getWeatherString()) :
                strat1.getTyreCompoundForLap(currentLap);
            car1.changeTyres(newTyre);
            std::cout << "New compound on : " << newTyre << std::endl;
        }

        // Vérification des arrêts planifiés pour la voiture 2
        if (strat2.hasPitStopOnLap(currentLap) && currentLap > 1) {
            std::cout << "\nPit stop planned for " << car2.getDriverName() << std::endl;
            std::string newTyre = isRaining ? 
                strat2.getTyreForWeather(weather.getWeatherString()) :
                strat2.getTyreCompoundForLap(currentLap);
            car2.changeTyres(newTyre);
            std::cout << "New compound on : " << newTyre << std::endl;
        }

        // Affichage des données
        std::cout << "\n" << car1.getDriverName() << ":\n";
        std::cout << "Actual Tyres : " << car1.getCurrentTyreCompound() 
                 << " (" << car1.getTyreCondition() << "%)\n";
        car1.collectAndDisplayData();

        std::cout << "\n" << car2.getDriverName() << ":\n";
        std::cout << "Actual Tyres : " << car2.getCurrentTyreCompound()
                 << " (" << car2.getTyreCondition() << "%)\n";
        car2.collectAndDisplayData();

        // Pause pour simulation temps réel
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    std::string grandPrixName;
    std::cout << "Name of the Grand Prix : ";
    std::getline(std::cin, grandPrixName);

    int totalLaps;
    std::cout << "How many laps  : ";
    std::cin >> totalLaps;

    // Initialisation des voitures et des capteurs
    Car car1(1, "Lando Norris");
    car1.addSensor(std::make_shared<SpeedSensor>(101));
    car1.addSensor(std::make_shared<TemperatureSensor>(102));
    car1.addSensor(std::make_shared<FuelSensor>(103));

    Car car2(2, "Oscar Piastri");
    car2.addSensor(std::make_shared<SpeedSensor>(201));
    car2.addSensor(std::make_shared<TemperatureSensor>(202));
    car2.addSensor(std::make_shared<FuelSensor>(203));

    std::cout << "\nStarting telemetry for  " << grandPrixName << "...\n";
    
    // Lancer la simulation interactive
    simulateRace(car1, car2, totalLaps);

    return 0;
}

