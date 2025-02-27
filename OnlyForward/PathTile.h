#pragma once

#include "Tile.h"

class PathTile: public Tile
{
public:
	PathTile();
	void onCollide();
};

