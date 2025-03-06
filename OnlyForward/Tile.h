#pragma once

#include <GLFW/glfw3.h>
#include "TileObject.h"

class Tile
{
public:
	int id;
	GLfloat red, green, blue;
	bool collidable;
	TileObject* object; // Attached object (ROCK, BUSH, MUSHROOMS, FLOWERS, etc.)

	Tile(int _id, GLfloat _red = 0.0f, GLfloat _green = 0.0f, GLfloat _blue = 0.0f, bool _collidable = true, TileObject* _object = nullptr);
	virtual ~Tile();

	virtual void onCollide() = 0;
};

