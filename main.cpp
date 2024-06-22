#include <iostream>
#include "Game.hpp"
#include "Entity/Player.hpp"
#include "Entity/EnumPlayer.hpp"

int main(int argc, char** argv) {
	Game *game = new Game();
	Player *player = new Player(); // get the information about the file

	while(true)
	{
		player->VisibleName();
		int choose = game->InitGame();
		if(choose == 1)
		{
			game->SetUpPlayer(player);
		}
		else if(choose == 2)
		{
			game->MenuStartGame();
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
