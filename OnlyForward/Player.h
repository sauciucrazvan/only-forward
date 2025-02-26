#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <utility>

#include "World.h"

class Player
{
public:
	std::vector<std::pair<int, int>> body;

	int playerX, playerY;
	static float speed;
	bool keyPressed = false, resetPressed = false;

	Player();

	void initPlayer();
	void drawPlayer();
	void processInput(GLFWwindow* window, World world);
};
