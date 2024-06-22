#include "Entity.hpp"

Entity::Entity() : MAX(30), attackSpeed(1)
{
    this->weapon = new Weapon*[MAX];
    this->armor = new Armor*[MAX];

    for (int i = 0; i < MAX; i++) {
        this->weapon[i] = nullptr;
        this->armor[i] = nullptr;
    }
}

Entity::~Entity()
{
    for(int i = 0; i < MAX; i++)
    {
        if(weapon[i] != nullptr)
        {
            delete weapon[i];
        }
        if(armor[i] != nullptr)
        {
            delete armor[i];
        }
    }
    delete []weapon;
    delete []armor;
}

double Entity::Damage() const 
{
    double damageRandom = RandomDouble(rangeDamage.first, rangeDamage.second);

    for(int i = 0; i < MAX; i++)
    {
        damageRandom += weapon[i]->Damage();
    }

    if(RandomDouble(critRate)) // crit rate effect
    {
        return damageRandom * 2.6 - damageRandom/(damageRandom - critRate);
    } 
    return damageRandom;   
}