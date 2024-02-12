#include "PokeTitle.h"
#include "ofApp.h"

PokeTitle::PokeTitle(std::string text, ofTrueTypeFont* fillFont, ofTrueTypeFont* outlineFont) : UiText(text, fillFont, 0, 40, ofGetWidth()) {
	this->textAlignment = UiText::TextAlignment::Center;	//	Sets up some default variables
	this->primaryColor = ofColor(255,255,0);
	this->pPrimaryFont = fillFont;
	this->secondaryColor = ofColor(0,0,255);
	this->pSecondaryFont = outlineFont;
}
void PokeTitle::onRender(float x, float y) {
	this->textColor = primaryColor;		//	Rendering the filled in font
	this->pFont = this->pPrimaryFont;
	UiText::onRender(x,y);

	this->textColor = secondaryColor;	//	Setup rendering the outline
	this->pFont = this->pSecondaryFont;
	UiText::onRender(x, y + 1);			//	Render the outline multiple times with several different offsets because the pokemon fonts don't match exactly for some reason. These offsets appear to remove most graphical glitches from the fonts not matching
	UiText::onRender(x, y);
	UiText::onRender(x, y-1);
	UiText::onRender(x+1, y);
	UiText::onRender(x-1, y);
	UiText::onRender(x-2, y);
	UiText::onRender(x + 2, y + 1);
}