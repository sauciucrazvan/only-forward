#pragma once
#include <GLFW/glfw3.h>
#include "TextRenderer.h"
class UI
{
protected:
	TextRenderer		infoText, /* Should be used to display the score, level */
						debugText; /* Used to display FPS */
	static TextRenderer announcementText; /* Used to display score increases */

	int framerate;
	static double announcementTime;

public:
	UI();
	void SetFPS(int _framerate);
	void Render(GLFWwindow* window);
	static void showAnnouncement(const char* text);
};

