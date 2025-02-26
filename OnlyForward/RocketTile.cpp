#include "RocketTile.h"

#include "Game.h"
#include "Player.h"
#include "Exception.h"

RocketTile::RocketTile() : Tile(75 / 255.0F, 170 / 255.0F, 82 / 255.0F, true) {}

void RocketTile::onCollide() {
    Player::speed = 2.0f;

    int tileX = Game::getInstance().player.playerX / TILE_SIZE;
    int tileY = Game::getInstance().player.playerY / TILE_SIZE;

    try {
        if (tileX < 0 || tileX >= MAP_WIDTH || tileY < 0 || tileY >= MAP_HEIGHT) {
            throw Exception((char*)"INVALID_TILE", (char*)"Invalid tile coordinates! (RocketTile)");
        }
        Game::getInstance().world.tileMap[tileY][tileX] = new PathTile();
    }
    catch (Exception e) {
        e.Print();
        return;
    }
}
