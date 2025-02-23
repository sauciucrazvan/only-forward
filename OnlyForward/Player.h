#pragma once

#include <GLFW/glfw3.h>

class Player
{
public:
	int playerX, playerY;

	void initPlayer();
	void drawPlayer(GLFWwindow* window);
	void processInput(GLFWwindow* window);
};

