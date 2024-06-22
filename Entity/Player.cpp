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
    pFile >> level;

    pFile.close();    
}

void Player::Show()
{
    std::cout << name << "\n";
    std::cout << HP << "\n";
    std::cout << rangeDamage.first << " " << rangeDamage.second << "\n";
    std::cout << attackSpeed << "\n";
    std::cout << critRate << "\n";
    std::cout << lifeSteel << "\n";
    std::cout << level << "\n";
}

void Player::ChangePropertyPlayer(int enumPlayer, std::string property)
{
    const std::string playerFile = "playerFile.txt";
    
    std::ifstream pFileIn(playerFile);
    if(!pFileIn)
    {
        pFileIn.close();
        throw std::runtime_error("Can not open the file " + playerFile);
    }

    std::vector<std::string> lines;
    std::string line;
    while(std::getline(pFileIn, line))
    {
        lines.push_back(line);
    }  
    pFileIn.close();

    lines[enumPlayer] = property; // changes the property's player in the line - 1

    std::ofstream pFileOut(playerFile);
    if(!pFileOut)
    {
        pFileOut.close();
        throw std::runtime_error("Can not open the file " + playerFile);
    }

    for(const std::string &x : lines)
    {
        pFileOut << x << "\n";
    }

    pFileOut.close();

    getPlayerFileInFo();
}

void Player::VisibleName()
{
    std::cout << "Name: ";
    if(name == "none")
    {
        std::cout << "The player has not a name\n";
    }
    else std::cout << name << "\n";
}