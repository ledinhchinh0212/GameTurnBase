#pragma once
#include "Entity.hpp"
#include <stdexcept>
#include <fstream>

class Player : public Entity
{
public:
    Player();
    void getPlayerFileInFo();
};