#pragma once
#include <string>
#include <utility>
#include "../Weapon/Weapon.hpp"
#include "../Armor/Armor.hpp"
#include "../Armor/GodGlovers.hpp"
#include "../Armor/IronCoat.hpp"
#include "../Armor/OmenWings.hpp"
#include "../Weapon/GodBow.hpp"
#include "../Weapon/MuramasaSword.hpp"
#include "../Weapon/Pistol.hpp"
#include "../Utility/Utility.hpp"

class Entity
{
protected:
    std::string name;
    double HP;
    std::pair<int, int> rangeDamage;
    int attackSpeed;
    double critRate;
    double lifeSteel;
    double level;
    const int MAX;

    Weapon **weapon;
    Armor **armor;

public:
    Entity();
    virtual ~Entity();

    std::string getName() const { return name; }
    double getHP() const { return HP; }
    std::pair<int, int> getRangeDamage() const { return rangeDamage; }
    int getAttackSpeed() const { return attackSpeed; }
    double getCritRate() const { return critRate; }
    double getLifeSteel() const { return lifeSteel; }
    double getLevel() const { return level; }
    void setName(std::string name) { this->name = name; }
    void setHP(double HP) { this->HP = HP; }
    void setRangeDamage(std::pair<int, int> rangeDamage) { this->rangeDamage = rangeDamage; }
    void setAttackSpeed(int attackSpeed) { this->attackSpeed = attackSpeed; }
    void setCritRate(double critRate) { this->critRate = critRate; }
    void setLifeSteel(double lifeSteel) { this->lifeSteel = lifeSteel; }
    void setLevel(double level) { this->level = level; }

    virtual double Damage() const;
};