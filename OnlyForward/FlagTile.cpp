#include "FlagTile.h"

#include "Game.h"

FlagTile::FlagTile() : Tile(199 / 255.0F, 191 / 255.0F, 46 / 255.0F, false) {
}

void FlagTile::onCollide() {
	Game::getInstance() += 100; Game::getInstance()++;
	std::cout << Game::getInstance();
	Game::getInstance().player.playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
	Game::getInstance().player.playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;
	Game::getInstance().world.generateMaze();
}