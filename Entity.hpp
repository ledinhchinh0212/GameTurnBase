#pragma once
#include <string>
#include <utility>

class Entity
{
protected:
    std::string name;
    double HP;
    std::pair<int, int> rangeDamage;
    int attackSpeed;
    double critRate;
    double lifeSteel;
public:
    Entity() {}
    std::string getName() const { return name; }
    double getHP() const { return HP; }
    std::pair<int, int> getRangeDamage() const { return rangeDamage; }
    int getAttackSpeed() const { return attackSpeed; }
    double getCritRate() const { return critRate; }
    double getLifeSteel() const { return lifeSteel; }
    void setName(std::string name) { this->name = name; }
    void setHP(double HP) { this->HP = HP; }
    void setRangeDamage(std::pair<int, int> rangeDamage) { this->rangeDamage = rangeDamage; }
    void setAttackSpeed(int attackSpeed) { this->attackSpeed = attackSpeed; }
    void setCritRate(double critRate) { this->critRate = critRate; }
    void setLifeSteel(double lifeSteel) { this->lifeSteel = lifeSteel; }
};