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

void Player::processInput(GLFWwindow* window, World world) {
    float speed = TILE_SIZE;

    bool alignedX = (static_cast<int>(this->playerX) % TILE_SIZE) == 0;
    bool alignedY = (static_cast<int>(this->playerY) % TILE_SIZE) == 0;

    if (!alignedX || !alignedY) return;

    if (!this->keyPressed) {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            if (this->playerY > 0 && world.collideCheckOnTile(this->playerX / TILE_SIZE, (this->playerY - speed) / TILE_SIZE)) {
                this->playerY -= speed;
                this->keyPressed = true;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            if (this->playerY + TILE_SIZE < MAP_HEIGHT * TILE_SIZE && world.collideCheckOnTile(this->playerX / TILE_SIZE, (this->playerY + speed) / TILE_SIZE)) {
                this->playerY += speed;
                this->keyPressed = true;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            if (this->playerX > 0 && world.collideCheckOnTile((this->playerX - speed) / TILE_SIZE, this->playerY / TILE_SIZE)) {
                this->playerX -= speed;
                this->keyPressed = true;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            if (this->playerX + TILE_SIZE < MAP_WIDTH * TILE_SIZE && world.collideCheckOnTile((this->playerX + speed) / TILE_SIZE, this->playerY / TILE_SIZE)) {
                this->playerX += speed;
                this->keyPressed = true;
            }
        }
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE) {
        this->keyPressed = false;
    }
}


