#ifndef TYRE_HPP
#define TYRE_HPP

#include <string>

class Tyre {
private:
    std::string compound;
    int condition;
    int degradationRate;

public:
    Tyre(const std::string& compound);
    void degrade(bool isRaining);
    bool needsPitStop() const;
    std::string getCompound() const;
    int getCondition() const;
};

#endif
