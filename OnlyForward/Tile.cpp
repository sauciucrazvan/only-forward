#include "Tile.h"

#include <GLFW/glfw3.h>

Tile::Tile(int _id, GLfloat _red, GLfloat _green, GLfloat _blue, bool _collidable, TileObject* _object) : id(_id), red(_red), green(_green), blue(_blue), collidable(_collidable), object(_object) {
}
Tile::~Tile() {}