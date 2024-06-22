#include "Entity.hpp"

Entity::Entity() : MAX(50)
{
    this->weapon = new Weapon*[MAX];
    this->armor = new Armor*[MAX];
}

Entity::~Entity()
{
    for(int i = 0; i < MAX; i++)
    {
        if(weapon[i] != nullptr)
        {
            delete[] weapon[i];
        }
        if(armor[i] != nullptr)
        {
            delete[] armor[i];
        }
    }
    delete []weapon;
    delete []armor;
}