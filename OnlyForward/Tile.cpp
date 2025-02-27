#include "Tile.h"

#include <GLFW/glfw3.h>

Tile::Tile(GLfloat _red, GLfloat _green, GLfloat _blue, bool _collidable) : red(_red), green(_green), blue(_blue), collidable(_collidable) {}
Tile::~Tile() {}