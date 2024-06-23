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
    std::cout << "Type your ingame:\n";
    std::string name;
    do 
    {
        std::getline(std::cin >> std::ws, name);
        if(!name.empty())
        {
           player->ChangePropertyPlayer(NAME, name);
        }
        else ErrorNoti::ErrorConsole(MESSAGE, "The name can not be empty");
    }
    while(name.empty());

    std::cout << "\nThe player's name has been set as \'" << name << "\'\n";
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
        else ErrorNoti::ErrorConsole(INVALID_INPUT);
    } while (OutRange(1, 5));
}

std::atomic<bool> running(true);
bool turnP = true;

void Game::ClearMapCheckFile(Player *&player)
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
        std::getline(fileIn >> std::ws, name);

        std::queue<NPC*> npc;
        for(int i = 0; i < size; i++)
        {
            if(name == "spider")
                npc.push(new Spider());
            if(name == "slime")
                npc.push(new Slime());
        }
        running = true;
        turnP = true;
        ClearMapStart(player, npc); 
    }

    fileIn.close();
}

void Game::GameStart(Player *&player, std::queue<NPC*>& npcs)
{
    int round = 1;
    while(running)
    {
        if(!npcs.empty())
        {
            NPC *npc = npcs.front();

            if(!isEnoughLevelToPlay(player, npc))
            {
                std::cout << "Your level is not enough to fight this npc\n";
                running = false;
            }
            else 
            {
                if(turnP) // player's turn
                {
                    double damage = player->ReturnDamage();
                    npc->setHP(npc->getHP() - damage);
                    if(player->isLifeSteel())
                    {
                        player->setHP(player->getHP() + damage);
	                   	if(player->getHP() >= player->getMaxHp())
	                   	{
	                       	player->setHP(player->getMaxHp());
	               		} 
                    }
                }
                else
                {
                    double damage = npc->ReturnDamage();
                    player->setHP(player->getHP() - damage);
                    if(npc->isLifeSteel())
                    {
                        npc->setHP(npc->getHP() + damage);
                        if(npc->getHP() >= npc->getMaxHp())
                        {
                            npc->setHP(npc->getMaxHp());
                        }
                    }
                } 
                turnP = !turnP;

                std::cout << player->getName() << ": ";
                if(player->getHP() <= 0) 
                    std::cout << "DIE";
                else std::cout << player->getHP();
                std::cout << "/" << player->getMaxHp() << "\n";
                
                std::cout << npc->getName() << ": ";
                if(npc->getHP() <= 0) 
                    std::cout << "DIE";
                else std::cout << npc->getHP();
                std::cout << "/" << npc->getMaxHp() << "\n";
                
                if(player->getHP() <= 0)
                {
                    std::cout << "You are lose !\n";
                    running = false;
                }
                else if(npc->getHP() <= 0) 
                {
                    npcs.pop();
                    player->setLevel(player->getLevel() + npc->getExp() + npc->getExp() * round * 0.10212);
                    delete npc;
                    std::cout << "\n\nNew round\n\n";
                }
            }
        }
        else 
        {
            if(player->getHP() > 0)
            {
                std::cout << "You won the map\n";
            }
            else std::cout << "loading?\n";
            std::cout << "\n";
            running = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1011)); 
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

void Game::ClearMapStart(Player *&player, std::queue<NPC*> &npc)
{
    std::thread countTimeThread(Game::CountTime, this, 90);
    std::thread gameStartThread(Game::GameStart, this, std::ref(player), std::ref(npc));

    countTimeThread.join();
    gameStartThread.join();
}

bool Game::isEnoughLevelToPlay(Player *player, NPC *npc)
{
    return player->getLevel() >= npc->getLevelRequest();
}
