#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "UI.h"
#include "Game.h"

double UI::announcementTime = 0.0;
TextRenderer UI::announcementText;

UI::UI() {
	this->framerate = 0;
	announcementText.setText("Hello world!"); // Greeting message, when you open the game
}

void UI::SetFPS(int _framerate) {
	this->framerate = _framerate;
}

void UI::Render(GLFWwindow* window) {
	this->infoText.setText(Game::toString(Game::getInstance()).c_str());
	this->infoText.renderText(5, 30, 2.0f, 1.0f, 1.0f, 0.0f);

	char buf[64];
	sprintf(buf, "FPS: %d", this->framerate);
	this->debugText.setText(buf);
	this->debugText.renderText(5, 5, 2.0f, 0.0f, 0.8f, 0.0f);

	double currentTime = glfwGetTime();
	if (currentTime - announcementTime < 2.0) { // Should stay for 2 seconds
		int windowWidth, windowHeight;
		glfwGetWindowSize(window, &windowWidth, &windowHeight);

		this->announcementText.renderText(5, 120, 2.0f, 1.0f, 1.0f, 0.0f);
	}
}

void UI::showAnnouncement(const char* text) {
	announcementTime = glfwGetTime();
	UI::announcementText.setText(text);
}