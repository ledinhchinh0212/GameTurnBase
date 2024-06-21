#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Player.hpp"

class Game
{
private:
    int choose;
    const char* playerFile;
public:
    Game();
    bool OutRange(int a, int b);
    int InitGame();
    bool SetUpPlayer(Player *player);
};