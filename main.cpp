#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

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
		}
		else if(choose == 3)
		{
			delete game;
			return 0;
		}
	}

	delete game;
	if(player != nullptr)
		delete player;	
	return 0;
}
