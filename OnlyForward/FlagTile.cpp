#include "FlagTile.h"

#include "Game.h"
#include "UI.h"

FlagTile::FlagTile() : Tile(199 / 255.0F, 191 / 255.0F, 46 / 255.0F, false) {
}

void FlagTile::onCollide() {
	double difference = glfwGetTime() - Game::levelStartTime;

	if(difference < 120)
		Game::getInstance() += 120 - difference; // Bonus for completing the level early

	Game::getInstance() += 100;
	Game::getInstance()++;
	
	UI::showAnnouncement("You've finished the level!");

	std::cout << Game::getInstance();
	Game::levelStartTime = glfwGetTime();
	Game::getInstance().player.playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
	Game::getInstance().player.playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;
	Game::getInstance().world.generateMaze();
}