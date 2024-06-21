#include "Player.hpp"

Player::Player() : Entity()
{
    this->getPlayerFileInFo();
}

void Player::getPlayerFileInFo()
{
    const char *playerFile = "playerFile.txt";
    std::ifstream pFile;
    pFile.open(playerFile);
    if(!pFile)
    {
        pFile.close();
        throw std::runtime_error("Can not open the file");
    }
    
    std::getline(pFile, name);
    pFile >> HP;
    pFile >> rangeDamage.first >> rangeDamage.second;
    pFile >> attackSpeed;
    pFile >> critRate;
    pFile >> lifeSteel;

    pFile.close();
}