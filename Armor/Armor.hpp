#pragma once
#include <string>

class Armor
{
protected:
    std::string ID;
    std::string name;
    double counterDamage; // counter damage
    double stamina; // mean armor
    int liftingAbility; // strength to use another weapon
public:
    Armor() : name("") {}
    
    void setName(std::string name) { this->name = name; }
    void setID(std::string ID) { this->ID = ID; }
    void setCounterDamage(double counterDamage) { this->counterDamage = counterDamage; }
    void setStamina(double stamina) { this->stamina = stamina; }
    void setLiftingAbility(int liftingAbility) { this->liftingAbility = liftingAbility; }

    std::string getName() const { return name; }
    double getCounterDamage() const { return counterDamage; }
    double getStamina() const { return stamina; }
    int getLiftingAbility() const { return liftingAbility; }
    std::string getID() const { return ID; }
};