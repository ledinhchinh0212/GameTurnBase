#include "Game.hpp"
#include <thread>

Game::Game() : playerFile("playerFile.txt"), NPC_Quest("NPC_Quest.txt") {}

int Game::InitGame()
{
    do
    {
        std::cout << "1. New Game\n";
        std::cout << "2. Continue\n";
        std::cout << "3. About This Game\n";
        std::cout << "4. Exit\n";

        std::cin >> choose;
        if(InRange(1, 4))
        {
            return choose;
        }
        std::cout << "Nhap khong hop le\n";
    }
    while(OutRange(1, 4));
}

bool Game::OutRange(int a, int b)
{
    return choose < a || choose > b;
}

bool Game::InRange(int a, int b)
{
    return !OutRange(a, b);
}

void Game::SetUpPlayer(Player *player)
{
    std::string name;
    do 
    {
        std::getline(std::cin >> std::ws, name);
        if(!name.empty())
        {
           player->ChangePropertyPlayer(NAME, name);
        }
        else Error::ErrorConsole(MESSAGE, "The name can not be empty");
    }
    while(name.empty());

    std::cout << "Nhap ten nguoi dung thanh cong\n";
}

int Game::MenuStartGame()
{
    std::cout << "1. Vuot Ai\n";
    std::cout << "2. Map Can Quet\n";
    std::cout << "3. Nhiem Vu\n";
    std::cout << "4. Trang bi\n";
    std::cout << "5. Thong tin nguoi choi\n";
    std::cout << "6. Thoat\n";

    do
    {
        std::cin >> choose;
        if(InRange(1, 5))
        {
            return choose;
        }
        else Error::ErrorConsole(INVALID_INPUT);
    } while (OutRange(1, 5));
}

void Game::ClearMapCheckFile()
{
    std::ifstream fileIn(NPC_Quest);
    if(!fileIn)
    {
        fileIn.close();
        throw std::runtime_error("Can not open the file " + NPC_Quest);
    }
    int complete;
    fileIn >> complete;

    if(complete == 1) // true (had clear the map)
    {
        std::cout << "You have already played this quest map today\n";
    }
    else 
    {
        int round, size;
        fileIn >> round >> size;
        std::string name;
        std::getline(fileIn, name);

        std::queue<NPC*> npc;
        for(int i = 0; i < size; i++)
        {
            if(name == "spider")
            {
                npc.push(new Spider());
            }    
        }
        ClearMapStart(npc); 
    }

    fileIn.close();
}

std::atomic<bool> running(true);

void Game::GameStart(std::queue<NPC*>& npc)
{
   while(running)
   {
       std::cout << "running\n";
       std::this_thread::sleep_for(std::chrono::milliseconds(250));
   }
}

void Game::CountTime(int seconds)
{
    while(seconds > 0 && running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds--;
        std::cout << "Time left: " << FormatTime(seconds) << "\n";
    }
    running = false;
}

void Game::ClearMapStart(std::queue<NPC*> &npc)
{
    std::thread countTimeThread(Game::CountTime, this, 90);
    std::thread gameStartThread(Game::GameStart, this, std::ref(npc));

    countTimeThread.join();
    gameStartThread.join();
}