#include "Tyre.hpp"

Tyre::Tyre(const std::string& compound) : compound(compound), condition(100) {
    if (compound == "Soft") degradationRate = 8;
    else if (compound == "Medium") degradationRate = 5;
    else if (compound == "Hard") degradationRate = 3;
    else if (compound == "Wet") degradationRate = 4;
    else if (compound == "Intermediate") degradationRate = 6;
}

void Tyre::degrade(bool isRaining) {
    float multiplier = 1.0;
    if (isRaining && (compound != "Wet" && compound != "Intermediate")) 
        multiplier = 2.5;
    else if (!isRaining && (compound == "Wet" || compound == "Intermediate"))
        multiplier = 2.0;

    condition -= static_cast<int>(degradationRate * multiplier);
    if (condition < 0) condition = 0;
}

bool Tyre::needsPitStop() const {
    return condition < 20;
}

std::string Tyre::getCompound() const {
    return compound;
}

int Tyre::getCondition() const {
    return condition;
}
