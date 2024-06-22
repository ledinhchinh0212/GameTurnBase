#pragma once
#include "Entity.hpp"
#include "EnumPlayer.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Player : public Entity
{
public:
    Player();
    void getPlayerFileInFo();
    void Show();
    void ChangePropertyPlayer(int, std::string);
};