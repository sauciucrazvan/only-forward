#include "WaterTile.h"
#include "Tile.h"
#include "Player.h"

#include <iostream>

WaterTile::WaterTile() : Tile(40 / 255.0F, 105 / 255.0F, 195 / 255.0F, true) {}

void WaterTile::onCollide() {
	Player::speed = 2.0f;
}