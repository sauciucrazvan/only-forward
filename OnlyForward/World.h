#pragma once

#include <GLFW/glfw3.h>

#include "Tile.h"

#include "GrassTile.h"

#define MAP_WIDTH  16
#define MAP_HEIGHT 16
#define TILE_SIZE  32

class World
{
public:
	Tile* tileMap[MAP_HEIGHT][MAP_WIDTH] = { new GrassTile() };
	World();
	//~World();

	void drawTileMap(GLFWwindow* window);
	bool collideCheckOnTile(int x, int y);
};

