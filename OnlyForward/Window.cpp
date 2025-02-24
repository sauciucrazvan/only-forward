#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <GLFW/glfw3.h>
#include <iostream>
#include <ctime>
#include "Window.h"
#include "World.h"
#include "Player.h"
#include "Game.h"

int Window::initWindow() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Gets the primary monitor and calculates 75% of the display resolution */
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    int windowWidth = (int) mode->width * 0.75,
        windowHeight = (int) mode->height * 0.75;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowWidth, windowHeight, "Only Forward", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Hopefully centers the window upon launch */
    int posX = (mode->width - windowWidth) / 2;
    int posY = (mode->height - windowHeight) / 2;
    glfwSetWindowPos(window, posX, posY);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Background color */
    glClearColor(32 / 255.0F, 85 / 255.0F, 158 / 255.0F, 1);

    /* Loop until the user closes the window */
    Game& game = Game::getInstance();
    game.player.initPlayer();           // Initializes the player coords

    double startTime = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Set up the projection and modelview matrices
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, windowWidth, windowHeight, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Apply camera transformation
        glTranslatef((GLfloat) -game.player.playerX + windowWidth / 2, (GLfloat) - game.player.playerY + windowHeight / 2, 0.0f);

        game.world.drawTileMap();                       // Draws the map
        game.player.processInput(window, game.world);   // Checks for inputs from the player
        game.player.drawPlayer();                       // Draws the player

        double currentTime = glfwGetTime();
        double elapsedTime = currentTime - startTime;

        if (elapsedTime >= 0.5) {
            if (Player::speed != 1.0f) Player::speed = 1.0f; // Resets the player's speed (used for powerups)
            startTime = currentTime;
        }
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
