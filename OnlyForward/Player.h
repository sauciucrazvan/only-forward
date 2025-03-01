#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <utility>

#include "World.h"

class Player
{
public:
	int						playerX, playerY;
	
	static float			speed;

	bool					keyPressed = false, 
							resetPressed = false;

	void					initPlayer();
	void					drawPlayer();
	void					processInput(GLFWwindow* window, World world);
};
