#include "Slime.hpp"

Slime::Slime()
{
    levelRequest = 2;
    exp = 0.3412;

    name = "Slime";
    HP = 50;
    rangeDamage = {4, 5};
    attackSpeed = 1;
    critRate = 0.19;
    lifeSteel = 0.1;

    MAX_HP = HP;
}