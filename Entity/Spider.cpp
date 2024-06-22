#include "Spider.hpp"

Spider::Spider() : NPC()
{
    levelRequest = 0;
    Exp = 0.201405;

    name = "Spider";
    HP = 10;
    rangeDamage = {3, 3};
    attackSpeed = 1;
    critRate = 0.25;
    lifeSteel = 0.109;

    MAX_HP = HP;
};