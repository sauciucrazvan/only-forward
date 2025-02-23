#pragma once

#include <GLFW/glfw3.h>
#include "World.h"

class Player
{
public:
	bool keyPressed = false;
	int playerX, playerY;

	void initPlayer();
	void drawPlayer(GLFWwindow* window);
	void processInput(GLFWwindow* window, World world);
};

