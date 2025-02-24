#pragma once

#include "Tile.h"

class RocketTile: public Tile
{
public:
	RocketTile();

	void onCollide();
};

