#pragma once
#include "ui/UiText.h"
class PokeTitle : public UiText
{
public:
	ofColor primaryColor;
	ofTrueTypeFont* pPrimaryFont;
	ofColor secondaryColor;
	ofTrueTypeFont* pSecondaryFont;

	PokeTitle(std::string text, ofTrueTypeFont* fillFont, ofTrueTypeFont* outlineFont);

	void onRender(float x, float y);
};

