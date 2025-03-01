#pragma once

#include <GLFW/glfw3.h>
#include "Tile.h"

class StarTile: public Tile
{
public:
	StarTile(GLfloat _red, GLfloat _green, GLfloat _blue);
	void onCollide();
};

