#include "FlagTile.h"
#include "FlagObject.h"

#include "Game.h"
#include "UI.h"

FlagTile::FlagTile() : Tile(199 / 255.0F, 191 / 255.0F, 46 / 255.0F, false, new FlagObject()) {
}

void FlagTile::onCollide() {
	double difference = glfwGetTime() - Game::levelStartTime;
	int bonus = 0;

	if(difference < 120)
		bonus = 120 - difference; // Bonus for completing the level early

	Game::getInstance() += 100 + bonus;
	Game::getInstance()++;
	
	char buf[128];
	sprintf_s(buf, "You've finished level #%d. (+%d score)", Game::getInstance().getLevel() - 1, (100 + bonus));
	UI::showAnnouncement(buf);

	std::cout << Game::getInstance();
	Game::levelStartTime = glfwGetTime();
	Game::getInstance().player.playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
	Game::getInstance().player.playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;
	Game::getInstance().world.generateMaze();
}