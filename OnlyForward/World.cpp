#include <GLFW/glfw3.h>
#include <iostream>

#include "World.h"
#include "Exception.h"

World::World() {
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
    char buf[256];
    try {
        if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
            sprintf_s(buf, "Out-of-bounds tile access at (%d, %d)", x, y);
            throw Exception((char*) "OUT-OF-BOUNDS", (char*) buf);
            return false;
        }

        if (!tileMap[y][x]) {
            sprintf_s(buf, "Trying to access uninitialized tile at (%d, %d)", x, y);
            throw Exception((char*) "UNINITIALIZED", (char*) buf);
            return false;
        }

        return tileMap[y][x]->collidable;
    }
    catch (Exception e) {
        e.Print();
        return false;
    }
}
