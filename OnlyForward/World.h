#pragma once

#include <GLFW/glfw3.h>

#include "Tile.h"

/*			TILES			*/		
#include "GrassTile.h"
#include "WaterTile.h"
#include "BridgeTile.h"
#include "StoneTile.h"
#include "SandTile.h"
#include "BarrierTile.h"
#include "RocketTile.h"
#include "FlagTile.h"
#include "PathTile.h"
#include "StarTile.h"

/*		 MAP SETTINGS		*/
#define MAP_WIDTH  72
#define MAP_HEIGHT 24
#define TILE_SIZE  32

class World
{
public:
	Tile* tileMap[MAP_HEIGHT][MAP_WIDTH] = { new GrassTile() };
	
	World();

	void drawTileMap();
	bool collideCheckOnTile(int x, int y);
	void generateMaze();
	void loadLevel(int level);
};

