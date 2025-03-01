    #include <GLFW/glfw3.h>

    #include "World.h"
    #include "Player.h"
    #include "Game.h"

    #include <iostream>
    #include "UI.h"

    float Player::speed = 1.0f;

    void Player::initPlayer() {
        playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
        playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;

        Game::levelStartTime = glfwGetTime();
    }

    void Player::drawPlayer() {
        glColor3f(80 / 255.0F, 173 / 255.0F, 82 / 255.0F);
        glBegin(GL_QUADS);
        glVertex2f(playerX, playerY);
        glVertex2f(playerX + TILE_SIZE, playerY);
        glVertex2f(playerX + TILE_SIZE, playerY + TILE_SIZE);
        glVertex2f(playerX, playerY + TILE_SIZE);
        glEnd();
    }

    void Player::processInput(GLFWwindow* window, World world) {
        float speed = TILE_SIZE * Player::speed;

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

        // DEBUG KEY
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS && !this->resetPressed) {
            this->playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
            this->playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;
            Game::getInstance().world.generateMaze();
            this->resetPressed = true;
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && !this->resetPressed) {
            this->playerX = (MAP_WIDTH / 2 - 1) * TILE_SIZE;
            this->playerY = (MAP_HEIGHT / 2 - 1) * TILE_SIZE;
        
            if (Game::getInstance() > -999) {
                Game::getInstance() -= 10;
                UI::showAnnouncement("LEVEL RESET! (-10 SCORE)");
                std::cout << Game::getInstance(); //debugging
            }
            this->resetPressed = true;
        }

        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE) {
            this->resetPressed = false;
        }
    }


