#ifndef WEATHER_HPP
#define WEATHER_HPP

#include <string>

enum class Weather {
    DRY,
    LIGHT_RAIN,
    HEAVY_RAIN
};

class WeatherCondition {
private:
    Weather currentWeather;
    float trackWetness;

public:
    WeatherCondition(Weather initial);
    bool isRaining() const;
    std::string getWeatherString() const;
    Weather getCurrentWeather() const;
    void updateWeather(Weather newWeather);
    float getTrackWetness() const;
};

#endif