#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

class Sensor {
protected:
    int id;
    std::string type;
    float value;

public:
    Sensor(int id, const std::string& type);
    virtual ~Sensor();
    virtual void collectData() = 0;
    virtual void displayData() const;
};

#endif
