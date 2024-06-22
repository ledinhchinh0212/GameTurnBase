#include "Pistol.hpp"

Pistol::Pistol() : Weapon()
{
    ID = "PI001";
    rangeDamage = {3, 7};
    weight = 0;
    critRate = 0.21405;
    lifeSteel = 0;
}