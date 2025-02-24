#pragma once

#include "Tile.h"

class FlagTile: public Tile
{
public:
	FlagTile();
	void onCollide();
};

