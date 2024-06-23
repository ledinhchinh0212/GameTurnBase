#include "Spider.hpp"

Spider::Spider() : NPC()
{
    levelRequest = 0;
    exp = 0.201405;

    name = "Spider";
    HP = 30;
    rangeDamage = {3, 3};
    attackSpeed = 1;
    critRate = 0.25;
    lifeSteel = 0.109;

    MAX_HP = HP;
};
