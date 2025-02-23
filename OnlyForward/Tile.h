#pragma once

#include <GLFW/glfw3.h>

class Tile
{
public:
	GLfloat red, green, blue;
	bool collidable;
	//Object object; // Attached object (ROCK, BUSH, etc.)
	//String assetSrc; // Link to the tile's asset

	Tile(GLfloat _red, GLfloat _green, GLfloat _blue, bool _collidable);
};

