#include <GLFW/glfw3.h>
#include <iostream>

#include "World.h"

World::World() {
    tileMap[0][0] = new WaterTile(), tileMap[0][1] = new WaterTile(), tileMap[1][0] = new WaterTile();
    tileMap[12][2] = new WaterTile(), tileMap[13][2] = new WaterTile(), tileMap[14][2] = new WaterTile();
    tileMap[11][2] = new WaterTile(), tileMap[12][3] = new BridgeTile(), tileMap[12][4] = new WaterTile(), tileMap[12][5] = new WaterTile();
    tileMap[11][3] = new BridgeTile(), tileMap[11][4] = new WaterTile(), tileMap[11][5] = new WaterTile();
    tileMap[10][6] = new WaterTile(), tileMap[15][6] = new WaterTile();
    tileMap[16][16] = new StoneTile(), tileMap[16][17] = new StoneTile(), tileMap[16][18] = new StoneTile();
    tileMap[15][16] = new SandTile(), tileMap[15][17] = new SandTile();

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if(!tileMap[i][j]) tileMap[i][j] = new GrassTile();
        }
    }
}

void World::drawTileMap(GLFWwindow* window) {
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-0.5, windowWidth - 0.5, windowHeight - 0.5, -0.5, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_FLAT);

    float mapWidth = MAP_WIDTH * TILE_SIZE,
          mapHeight = MAP_HEIGHT * TILE_SIZE,
          offsetX = (windowWidth - mapWidth) / 2.0f, 
          offsetY = (windowHeight - mapHeight) / 2.0f;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Tile tile = *(tileMap[y][x]);

            int xPos = static_cast<int>(x * TILE_SIZE + offsetX),
                yPos = static_cast<int>(y * TILE_SIZE + offsetY);

            glColor3f(tile.red, tile.green, tile.blue);

            glBegin(GL_QUADS);
            glVertex2f(xPos, yPos);
            glVertex2f(xPos + TILE_SIZE, yPos);
            glVertex2f(xPos + TILE_SIZE, yPos + TILE_SIZE);
            glVertex2f(xPos, yPos + TILE_SIZE);
            glEnd();
        }
    }
}

bool World::collideCheckOnTile(int x, int y) {
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
        std::cerr << "ERROR: Out-of-bounds tile access (" << x << ", " << y << ")" << std::endl;
        return false;
    }

    if (!tileMap[y][x]) {
        std::cerr << "ERROR: Accessing uninitialized tile at (" << x << ", " << y << ")" << std::endl;
        return false;
    }

    return tileMap[y][x]->collidable;
}
