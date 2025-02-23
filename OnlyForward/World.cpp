#include <GLFW/glfw3.h>

#include "World.h"

int* World::getTileMap() { return *tileMap; }

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
            int tile = tileMap[y][x];

            float xPos = x * TILE_SIZE + offsetX,
                  yPos = y * TILE_SIZE + offsetY;

            if (tile == 0) glColor3f(0.0f, 1.0f, 0.0f);
            else if (tile == 1) glColor3f(0.0f, 0.0f, 1.0f);
            else if (tile == 2) glColor3f(1.0f, 1.0f, 0.0f);

            glBegin(GL_QUADS);
            glVertex2f(xPos, yPos);
            glVertex2f(xPos + TILE_SIZE, yPos);
            glVertex2f(xPos + TILE_SIZE, yPos + TILE_SIZE);
            glVertex2f(xPos, yPos + TILE_SIZE);
            glEnd();
        }
    }
}
