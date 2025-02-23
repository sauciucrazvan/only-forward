#include <GLFW/glfw3.h>

#include "World.h"
#include "Player.h"

void Player::initPlayer() {
    playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
    playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;
}

void Player::drawPlayer(GLFWwindow* window) {
    int windowWidth, windowHeight;
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    float mapWidth = MAP_WIDTH * TILE_SIZE,
          mapHeight = MAP_HEIGHT * TILE_SIZE,
          offsetX = (windowWidth - mapWidth) / 2.0f,
          offsetY = (windowHeight - mapHeight) / 2.0f;

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(playerX + offsetX, playerY + offsetY);
    glVertex2f(playerX + TILE_SIZE + offsetX, playerY + offsetY);
    glVertex2f(playerX + TILE_SIZE + offsetX, playerY + TILE_SIZE + offsetY);
    glVertex2f(playerX + offsetX, playerY + TILE_SIZE + offsetY);
    glEnd();
}

void Player::processInput(GLFWwindow* window) {
    float speed = TILE_SIZE * .5f;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && playerY > 0) {
        glfwWaitEventsTimeout(0.5);
        playerY -= speed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && playerY + TILE_SIZE < MAP_HEIGHT * TILE_SIZE) {
        glfwWaitEventsTimeout(0.5);
        playerY += speed;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && playerX > 0) {
        glfwWaitEventsTimeout(0.5);
        playerX -= speed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && playerX + TILE_SIZE < MAP_WIDTH * TILE_SIZE) {
        glfwWaitEventsTimeout(0.5);
        playerX += speed;
    }
}
