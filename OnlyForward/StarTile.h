#pragma once

#include <GLFW/glfw3.h>
#include "Tile.h"

class StarTile: public Tile
{
public:
	StarTile();
	void onCollide();
};

