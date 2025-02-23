#include <GLFW/glfw3.h>

#include "Window.h"
#include "World.h"
#include "Player.h"

int Window::initWindow() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Gets the primary monitor and calculates 75% of the display resolution */
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    int windowWidth = mode->width * 0.75, windowHeight = mode->height * 0.75;

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

    /* Loop until the user closes the window */
    World world; Player player;
    player.initPlayer();           // Initiliazes the player coords

    /* Background color */
    glClearColor(32 / 255.0F, 85 / 255.0F, 158 / 255.0F, 1);

    while (!glfwWindowShouldClose(window))
    {
        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        world.drawTileMap(window);            // Draws the map
        player.processInput(window, world);   // Checks for inputs from the player
        player.drawPlayer(window);            // Draws the player

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}