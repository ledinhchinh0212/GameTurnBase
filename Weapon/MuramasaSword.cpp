#include "MuramasaSword.hpp"

MuramasaSword::MuramasaSword() : Weapon()
{
    ID = "MS001";
    name = "MuramasaSword";
    rangeDamage = {6, 15};
    weight = 3;
    critRate = 0.7659;
    lifeSteel = 0.55;
}