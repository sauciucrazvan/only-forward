#include "RocketTile.h"
#include "Player.h"

RocketTile::RocketTile() : Tile(75 / 255.0F, 170 / 255.0F, 82 / 255.0F, true) {}

void RocketTile::onCollide() {
	Player::speed = 2.0f;
}