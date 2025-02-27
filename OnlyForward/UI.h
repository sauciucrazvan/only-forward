#pragma once
#include "TextRenderer.h"
class UI
{
protected:
	TextRenderer infoText; /* Should be used to display the score, level */
public:
	UI();
	void Render();
};

