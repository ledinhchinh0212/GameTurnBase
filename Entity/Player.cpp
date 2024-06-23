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
    pFile >> HP; MAX_HP = HP;
    pFile >> rangeDamage.first >> rangeDamage.second;
    pFile >> attackSpeed;
    pFile >> critRate;
    pFile >> lifeSteel;
    pFile >> level;

    int size;
    pFile >> size;
    for(int i = 0; i < size; i++)
    {
        std::string ID;
        pFile >> ID;
        std::string startWith = ID.substr(0, 2);
        if(startWith == "GG")
            armor[i] = new GodGlovers();
        else if(startWith == "IC")
            armor[i] = new IronCoat();
        else if(startWith == "OW");
            // armor[i] = new OmenWings();
        
        if(startWith == "GB")
            weapon[i] = new GodBow();
        else if(startWith == "MS")
            weapon[i] = new MuramasaSword();
        else if(startWith == "PI")
            weapon[i] = new Pistol();   
    }

    pFile.close();    
}

void Player::Show()
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Level: " << (int)level << "\n";
    std::cout << "Max HP: " <<  HP << "\n";
    std::cout << "Range Damage: " << rangeDamage.first << " " << rangeDamage.second << "\n";
    std::cout << "Attack Speed: " << attackSpeed << "\n";
    std::cout << "Crit Rate: " << critRate << "\n";
    std::cout << "Life Steel: " << lifeSteel << "\n";
    std::cout << std::endl;

    std::cout << "Weapon:\n";
    bool isWeapon = false;
    for(int i = 0; i < MAX; i++)
    {
        if(weapon[i] != nullptr)
        {
            std::cout << "\t" << weapon[i]->getID() << " " << weapon[i]->getName() << "\n";
            isWeapon = true;
        }
    }
    if(!isWeapon) std::cout << "\tPlayer has no any weapon yet\n";

    bool isArmor = false;
    std::cout << "\nArmor:\n";
    for(int i = 0; i < MAX; i++)
    {
        if(armor[i] != nullptr)
        {
            std::cout << "\t" << armor[i]->getID() << " " << armor[i]->getName() << "\n";
            isArmor = true;
        }
    }
    if(!isArmor) std::cout << "\tPlayer has no any armor yet\n";
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

void Player::WriteFilePlayer()
{
    const std::string playerFile = "playerFile.txt";
    std::ofstream fileP(playerFile, std::ofstream::trunc);
    if(!fileP)
    {
        fileP.close();
        throw std::runtime_error("Can not open the file " + playerFile);
    }
    fileP << name << "\n";
    fileP << HP << "\n";
    fileP << rangeDamage.first << " " << rangeDamage.second << "\n";
    fileP << attackSpeed << "\n";
    fileP << critRate << "\n";
    fileP << lifeSteel << "\n";
    fileP << level << "\n";
    int count = 0;
    for(int i = 0; i < MAX; i++)
    {
        if(armor[i] != nullptr)
            count++;
        if(weapon[i] != nullptr)
            count++;
    }
    fileP << count << "\n";
    for(int i = 0; i < MAX; i++)
    {
        if(armor[i] != nullptr)
            fileP << armor[i]->getID() << "\n";
        if(weapon[i] != nullptr)
            fileP << weapon[i]->getID() << "\n";
    }
    fileP.close();
}