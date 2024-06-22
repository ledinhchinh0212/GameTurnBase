#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "EnumPlayer.hpp"

int main(int argc, char** argv) {
	Game *game = new Game();
	Player *player = nullptr;

	while(true)
	{
		int choose = game->InitGame();
		if(choose == 1)
		{
			player = new Player();
			game->SetUpPlayer(player);
			// player->Show();
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
	if(player != nullptr)
		delete player;	
	return 0;
}
