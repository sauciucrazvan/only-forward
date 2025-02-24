#pragma once

#include <GLFW/glfw3.h>
#include "World.h"

class Player
{
protected:
	bool keyPressed = false;
	int playerX, playerY;
public:
	void initPlayer();
	void drawPlayer(GLFWwindow* window);
	void processInput(GLFWwindow* window, World world);
};

