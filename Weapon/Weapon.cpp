#include "Weapon.hpp"

Weapon::Weapon() : weight(0) {}

double Weapon::Damage() const 
{
    double damageRandom = RandomDouble(rangeDamage.first, rangeDamage.second);
    if(RandomDouble(critRate))
    {
        return damageRandom * 1.375;
    }
    return damageRandom;
}

bool Weapon::LifeSteel() const 
{
    return RandomDouble(lifeSteel);
}