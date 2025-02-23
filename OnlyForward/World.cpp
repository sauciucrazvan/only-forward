#include <GLFW/glfw3.h>
#include <iostream>

#include "World.h"

#include "WaterTile.h"

World::World() {
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            tileMap[i][j] = new GrassTile();
        }
    }

    tileMap[0][0] = new WaterTile(), tileMap[0][1] = new WaterTile(), tileMap[1][0] = new WaterTile();
}

void World::drawTileMap(GLFWwindow* window) {
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, windowWidth, windowHeight, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float mapWidth = MAP_WIDTH * TILE_SIZE,
          mapHeight = MAP_HEIGHT * TILE_SIZE,
          offsetX = (windowWidth - mapWidth) / 2.0f, 
          offsetY = (windowHeight - mapHeight) / 2.0f;

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Tile tile = *(tileMap[y][x]);

            float xPos = x * TILE_SIZE + offsetX,
                  yPos = y * TILE_SIZE + offsetY;

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
        std::cerr << "Error: Out-of-bounds tile access (" << x << ", " << y << ")" << std::endl;
        return false;
    }

    if (!tileMap[x][y]) {
        std::cerr << "Error: Accessing uninitialized tile at (" << x << ", " << y << ")" << std::endl;
        return false;
    }

    return tileMap[x][y]->collidable;
}

//World::~World() {
//    for (int i = 0; i < MAP_HEIGHT; ++i) {
//        for (int j = 0; j < MAP_WIDTH; ++j) {
//            delete tileMap[i][j];
//            tileMap[i][j] = nullptr;
//        }
//    }
//}
