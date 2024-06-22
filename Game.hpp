#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>
#include "Player.hpp"
#include "Error/Error.hpp"

class Game
{
private:
    int choose;
    const char* playerFile;
public:
    Game();
    bool OutRange(int a = INT_MIN, int b = INT_MAX);
    int InitGame();
    bool SetUpPlayer(Player *player);
    int MenuStartGame();
};