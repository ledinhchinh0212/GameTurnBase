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
#include "Error-Notification/ErrorNoti.hpp"
#include "Entity/NPC.hpp"
#include "Entity/Spider.hpp"
#include "Entity/Entity.hpp"
#include "Entity/Slime.hpp"

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
    
    void ClearMapCheckFile(Player*&);
    void ClearMapStart(Player*&, std::queue<NPC*>&);

    void CountTime(int seconds);

    void GameStart(Player*&, std::queue<NPC*>&);

    bool isEnoughLevelToPlay(Player *player, NPC *npc);
};