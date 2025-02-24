#pragma once

#include <GLFW/glfw3.h>
#include "World.h"

class Player
{
public:
	bool keyPressed = false, resetPressed = false;
	int playerX, playerY;
	static float speed;
	void initPlayer();
	void drawPlayer();
	void processInput(GLFWwindow* window, World world);
};
