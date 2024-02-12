#pragma once
#include "../ui/UiBox.h"
#include "ofMain.h"
#include "ui/pokequiz/PokeTitle.h"

class ScreenWelcome : public UiElement
{
public:
	static ofTrueTypeFont titleFont;
	static ofTrueTypeFont titleOutlineFont;

	std::shared_ptr<PokeTitle> titleElement;

	ScreenWelcome();

	void onUpdate();
	bool onClick(float x, float y);
};

