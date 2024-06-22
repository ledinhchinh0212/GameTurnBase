#include "Game.hpp"

Game::Game() : playerFile("playerFile.txt") {}

int Game::InitGame()
{
    do
    {
        std::cout << "1. New Game\n";
        std::cout << "2. Continue\n";
        std::cout << "3. About This Game\n";
        std::cout << "4. Exit\n";

        std::cin >> choose;
        if(!OutRange(1, 4))
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

bool Game::SetUpPlayer(Player *player)
{
    std::string name;
    do 
    {
        std::getline(std::cin >> std::ws, name);
        if(!name.empty())
        {
           player->ChangePropertyPlayer(NAME, name);
        }
        else std::cout << "The name can not be empty\n";
    }
    while(name.empty());
    
    std::cout << "Nhap ten nguoi dung thanh cong\n";
}