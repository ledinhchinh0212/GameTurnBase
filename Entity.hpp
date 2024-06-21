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
};