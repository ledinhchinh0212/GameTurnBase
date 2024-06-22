#pragma once
#include <utility>
#include <string>

class Weapon
{
protected:
    std::string ID;
    std::pair<int, int> rangeDamage; // overwrite Range Damage of Player
    int weight; // bonus weight of weapon (effect to attack speed)
    double critRate;
    double lifeSteel;
public:
    Weapon() {}

    void setRangeDamage(std::pair<int, int> rangeDamage) { this->rangeDamage = rangeDamage; }
    void setWeight(int weight) { this->weight = weight; }
    void setCritRate(double critRate) { this->critRate = critRate; }
    void setLifeSteel(double lifeSteel) { this->lifeSteel = lifeSteel; }
    void setID(std::string ID) { this->ID = ID; }
    int getWeight() const { return weight; }
    double getCritRate() const { return critRate; }
    double getLifeSteel() const { return lifeSteel; }
    std::pair<int, int> getRangeDamge() const { return rangeDamage; }
    std::string getID() const { return ID; }
};