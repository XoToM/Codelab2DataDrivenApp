#pragma once
#include "../ui/UiBox.h"
#include "ofMain.h"
#include "ui/pokequiz/PokeTitle.h"

class ScreenWelcome : public UiBox
{
public:
	ofTrueTypeFont titleFont;
	ofTrueTypeFont titleOutlineFont;

	std::shared_ptr<PokeTitle> titleElement;

	ScreenWelcome();

	void onUpdate();
};

