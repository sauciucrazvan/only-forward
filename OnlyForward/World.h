#pragma once

#include <GLFW/glfw3.h>

#define MAP_WIDTH  16
#define MAP_HEIGHT 16
#define TILE_SIZE  32

class World
{
public:
	int tileMap[MAP_HEIGHT][MAP_WIDTH] = { 1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,
										   1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,
										   2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int* getTileMap();
	void drawTileMap(GLFWwindow* window);
};

