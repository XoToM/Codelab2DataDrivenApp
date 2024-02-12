#pragma once
#include "ui/UiBox.h"

class ScreenError : public UiElement
{
public:
	ScreenError();

	//	We should redirect the user back to the welcome screen if an error has occured
	bool onClick(float x, float y);
};

