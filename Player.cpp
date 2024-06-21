#include "Player.hpp"

Player::Player() : Entity()
{
    this->name = "none";
    this->HP = 15;
    this->rangeDamage = {0, 5};
    this->attackSpeed = 1;
    this->critRate = 0;
    this->lifeSteel = 0;
}