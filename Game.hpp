#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <climits>
#include <queue>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include "Entity/Player.hpp"
#include "Error/Error.hpp"
#include "Entity/NPC.hpp"
#include "Entity/Spider.hpp"
#include "Entity/Entity.hpp"

class Game
{
private:
    int choose;
    const std::string playerFile;
    const std::string NPC_Quest;
public:
    Game();
    
    bool OutRange(int a = INT_MIN, int b = INT_MAX);
    bool InRange(int a = INT_MIN, int b = INT_MAX);
    
    int InitGame();
    void SetUpPlayer(Player *player);
    int MenuStartGame();
    
    void ClearMapCheckFile();
    void ClearMapStart(std::queue<NPC*>&);
};