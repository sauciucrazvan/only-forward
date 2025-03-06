#include "StarTile.h"

#include "Game.h"
#include "Player.h"
#include "Exception.h"
#include "UI.h"

#include "StarObject.h"

StarTile::StarTile() : Tile(100, 60 / 255.0f, 162 / 255.0f, 82 / 255.0f, true, new StarObject()) {}

void StarTile::onCollide() {
    Game::getInstance() *= 1.05; //+5% bonus
    UI::showAnnouncement("+5% BONUS SCORE!");

    // Reset the tile
    int tileX = Game::getInstance().player.playerX / TILE_SIZE;
    int tileY = Game::getInstance().player.playerY / TILE_SIZE;

    try {
        if (tileX < 0 || tileX >= MAP_WIDTH || tileY < 0 || tileY >= MAP_HEIGHT) {
            throw Exception((char*)"INVALID_TILE", (char*) "Invalid tile coordinates! (StarTile)");
        }
        Game::getInstance().world.tileMap[tileY][tileX] = new PathTile();
    }
    catch (Exception e) {
        e.Print();
        return;
    }
}