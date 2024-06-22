#pragma once
#include <string>

class Armor
{
protected:
    std::string ID;
    double counterDamage;
    double stamina;
    int liftingAbility;
public:
    Armor() {}
    void setID(std::string ID) { this->ID = ID; }
    void setCounterDamage(double counterDamage) { this->counterDamage = counterDamage; }
    void setStamina(double stamina) { this->stamina = stamina; }
    void setLiftingAbility(int liftingAbility) { this->liftingAbility = liftingAbility; }
    double getCounterDamage() const { return counterDamage; }
    double getStamina() const { return stamina; }
    int getLiftingAbility() const { return liftingAbility; }
    std::string getID() const { return ID; }
};