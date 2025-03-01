#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <ctime>

#include "Window.h"
#include "TextRenderer.h"
#include "World.h"
#include "Player.h"
#include "Game.h"
#include "UI.h"

int framerate = 0;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void CalculateFrameRate()
{
    static float framesPerSecond = 0.0f;
    static int fps;
    static float lastTime = 0.0f;
    float currentTime = glfwGetTime();
    ++framesPerSecond;
    
    framerate = fps;
    
    if (currentTime - lastTime > 1.0f)
    {
        lastTime = currentTime;
        fps = (int)framesPerSecond;
        framesPerSecond = 0;
    }
}


int Window::initWindow() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Gets the primary monitor and calculates 75% of the display resolution */
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    int windowWidth = (int)mode->width * 0.75,
        windowHeight = (int)mode->height * 0.75;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowWidth, windowHeight, "Only Forward", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Registers the window resize callback, hopefully that fixes the blurry issue (hopefully) */
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Hopefully centers the window upon launch */
    int posX = (mode->width - windowWidth) / 2;
    int posY = (mode->height - windowHeight) / 2;
    glfwSetWindowPos(window, posX, posY);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Enable anti-aliasing */
    glEnable(GL_MULTISAMPLE);

    /* Set up texture filtering */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    /* Background color */
    glClearColor(32 / 255.0F, 85 / 255.0F, 158 / 255.0F, 1);

    /* Loop until the user closes the window */
    Game& game = Game::getInstance();
    game.player.initPlayer(); // Initializes the player coords

    UI userInterface;

    double startTime = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Apply camera transformation
        glTranslatef((GLfloat)-game.player.playerX + windowWidth / 2, windowHeight / 8, 0.0f);

        game.world.drawTileMap();                     // Draws the map
        game.player.processInput(window, game.world); // Checks for inputs from the player
        game.player.drawPlayer();                     // Draws the player
        
        // Reset coordinate system for UI
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, windowWidth, windowHeight, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Render UI
        CalculateFrameRate();
        userInterface.SetFPS(framerate);
        userInterface.Render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

