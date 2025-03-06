#include "WaterTile.h"
#include "Tile.h"
#include "Game.h"
#include "Player.h"

#include <iostream>

WaterTile::WaterTile() : Tile(7, 40 / 255.0F, 105 / 255.0F, 195 / 255.0F, true) {}

void WaterTile::onCollide() {
}