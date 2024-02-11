#include "ScreenWelcome.h"
#include "../ui/UiText.h"
#include "ofApp.h"
#include "ui/pokequiz/PokeTitle.h"

ScreenWelcome::ScreenWelcome() : UiBox(0, 0, ofGetWidth(), ofGetHeight()) {
	//	Load fonts for the title screen. These are loaded in here instead of in ofApp because font this big is only used here
	this->titleFont.load("fonts/Pokemon Solid.ttf", 110);	//	https://befonts.com/pokemon-font.html
	this->titleOutlineFont.load("fonts/Pokemon Hollow.ttf", 110);	//	https://befonts.com/pokemon-font.html

	this->titleElement = this->addChild(make_shared<PokeTitle>("Poke Quiz", &this->titleFont, &this->titleOutlineFont));	//	Define ui elements
	this->addChild(make_shared<UiText>("By Dawid Kawka", &ofApp::normalFont, 20, ofGetHeight() - 50));
	this->addChild(make_shared<UiText>("Click anywhere to start", &ofApp::subTitleFont, 0, ofGetHeight()/2 + 50, ofGetWidth()))->textAlignment = UiText::TextAlignment::Center;
}

void ScreenWelcome::onUpdate() {
	float timeLoopOffset = (float)(ofGetElapsedTimeMillis() % 3000) / 3000 * 2 * PI;	//	Calculate how far into the movement loop we are

	this->titleElement->yPosition = 40 + 10 * sinf(timeLoopOffset);	//	Make the title move a bit
	
	UiBox::onUpdate();	//	Update the child elements
}