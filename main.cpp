#include <iostream>
#include "Game.hpp"
#include "Entity/Player.hpp"
#include "Entity/EnumPlayer.hpp"
#include "Date.hpp"
#include "Utility/Utility.hpp"

int main(int argc, char** argv) {
	Game *game = new Game();
	Player *player = new Player(); // get the information about the file

	while(true)
	{
		player->VisibleName();
		Date date;
		std::cout << "Time: " << date.RealDate() << "\n";
		std::cout << std::endl;
		int choose = game->InitGame();
		if(choose == 1)
		{
			game->SetUpPlayer(player);
			TypeToContinue(DELETE); 
		}
		else if(choose == 2)
		{
			while(true)
			{
				int choose1 = game->MenuStartGame();
				if(choose1 == 2) // clear map
				{
					game->ClearMapCheckFile(player);
				}
				else if(choose1 == 4)
				{	
					std::cout << "You get here\n";
				}
				else if(choose1 == 5)
				{
					player->Show();
				}
				else if(choose1 == 6) break;

				player->setHP(player->getMaxHp());
				player->WriteFilePlayer();
			}
		}
		else if(choose == 3) break;
		
		player->setHP(player->getMaxHp());
		player->WriteFilePlayer();
	}

	delete game;
	delete player;	
	return 0;
}
