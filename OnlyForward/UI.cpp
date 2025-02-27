#include "UI.h"
#include "Game.h"

UI::UI() {

}

void UI::Render() {
	this->infoText.setText(Game::toString(Game::getInstance()).c_str());
	this->infoText.renderText(50, 30, 2.0f, 1.0f, 1.0f, 0.0f);
}