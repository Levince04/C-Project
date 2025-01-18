#include "Weather.hpp"

WeatherCondition::WeatherCondition(Weather initial) : currentWeather(initial) {
    switch (initial) {
        case Weather::DRY: trackWetness = 0; break;
        case Weather::LIGHT_RAIN: trackWetness = 50; break;
        case Weather::HEAVY_RAIN: trackWetness = 100; break;
    }
}

bool WeatherCondition::isRaining() const {
    return currentWeather != Weather::DRY;
}

std::string WeatherCondition::getWeatherString() const {
    switch (currentWeather) {
        case Weather::DRY: return "Sec";
        case Weather::LIGHT_RAIN: return "Pluie légère";
        case Weather::HEAVY_RAIN: return "Forte pluie";
        default: return "Inconnu";
    }
}

Weather WeatherCondition::getCurrentWeather() const {
    return currentWeather;
}

void WeatherCondition::updateWeather(Weather newWeather) {
    currentWeather = newWeather;
    switch (newWeather) {
        case Weather::DRY: trackWetness = std::max(0.0f, trackWetness - 20); break;
        case Weather::LIGHT_RAIN: trackWetness = std::min(100.0f, trackWetness + 10); break;
        case Weather::HEAVY_RAIN: trackWetness = std::min(100.0f, trackWetness + 30); break;
    }
}

float WeatherCondition::getTrackWetness() const {
    return trackWetness;
}