#pragma once
#include "TextRenderer.h"
class UI
{
protected:
	TextRenderer infoText; /* Should be used to display the score, level */
	TextRenderer debugText; /* Used to display FPS */

	int framerate;
public:
	UI();
	void SetFPS(int _framerate);
	void Render();
};

