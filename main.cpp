#include <iostream>
#include "Game.hpp"
#include "Entity/Player.hpp"
#include "Entity/EnumPlayer.hpp"
#include "Date.hpp"

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
		}
		else if(choose == 2)
		{
			int choose1 = game->MenuStartGame();
			if(choose1 == 2) // clear map
			{
				game->ClearMapCheckFile();
			}
			else if(choose1 == 5)
			{
				
			}
		}
		else if(choose == 3)
		{
			break;
		}
	}

	delete game;
	delete player;	
	return 0;
}
