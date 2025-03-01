#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "UI.h"
#include "Game.h"

UI::UI() {
	this->framerate = 0;
}

void UI::SetFPS(int _framerate) {
	this->framerate = _framerate;
}

void UI::Render() {
	this->infoText.setText(Game::toString(Game::getInstance()).c_str());
	this->infoText.renderText(5, 30, 2.0f, 1.0f, 1.0f, 0.0f);

	char buf[64];
	sprintf(buf, "FPS: %d", this->framerate);
	this->debugText.setText(buf);
	this->debugText.renderText(5, 5, 2.0f, 0.0f, 0.8f, 0.0f);
}