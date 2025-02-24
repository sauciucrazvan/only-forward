#include "Tile.h"

#include <GLFW/glfw3.h>

Tile::Tile(GLfloat _red, GLfloat _green, GLfloat _blue, bool _collidable) {
	this->red = _red, this->green = _green, this->blue = _blue;
	this->collidable = _collidable;
}
Tile::~Tile() {}

void Tile::onCollide() {}