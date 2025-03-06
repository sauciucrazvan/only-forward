#include "GrassTile.h"

#include "Game.h"
#include "Exception.h"

GrassTile::GrassTile() : Tile(3, 73 / 255.0F, 149 / 255.0F, 82 / 255.0F, true) {}

void GrassTile::onCollide() {
    int tileX = Game::getInstance().player.playerX / TILE_SIZE;
    int tileY = Game::getInstance().player.playerY / TILE_SIZE;

    try {
        if (tileX < 0 || tileX >= MAP_WIDTH || tileY < 0 || tileY >= MAP_HEIGHT) {
            throw Exception((char*) "INVALID_TILE", (char*) "Invalid tile coordinates! (Grass Tile)");
        }
        Game::getInstance().world.tileMap[tileY][tileX] = new PathTile();
    }
    catch (Exception e) {
        e.Print();
        return;
    }
}
