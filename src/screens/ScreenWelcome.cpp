#include "ScreenWelcome.h"
#include "ui/UiText.h"
#include "ofApp.h"
#include "ui/pokequiz/PokeTitle.h"

#include "ScreenDifficultySelect.h"
#include "ScreenError.h"


ofTrueTypeFont ScreenWelcome::titleFont;
ofTrueTypeFont ScreenWelcome::titleOutlineFont;

ScreenWelcome::ScreenWelcome() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	//	Load fonts for the title screen if they are not loaded already. These are loaded in here instead of in ofApp because font this big is only used here
	if(!ScreenWelcome::titleFont.isLoaded()) ScreenWelcome::titleFont.load("fonts/Pokemon Solid.ttf", 110);	//	https://befonts.com/pokemon-font.html
	if (!ScreenWelcome::titleOutlineFont.isLoaded())ScreenWelcome::titleOutlineFont.load("fonts/Pokemon Hollow.ttf", 110);	//	https://befonts.com/pokemon-font.html

	this->titleElement = this->addChild(make_shared<PokeTitle>("Poke Quiz", &ScreenWelcome::titleFont, &ScreenWelcome::titleOutlineFont));	//	Define ui elements
	this->addChild(make_shared<UiText>("By Dawid Kawka", &ofApp::normalFont, 20, ofGetHeight() - 50))->textColor = ofColor(255,255,255);
	auto centerText = this->addChild(make_shared<UiText>("Click anywhere to start", &ofApp::subTitleFont, 0, ofGetHeight() / 2 + 50, ofGetWidth()));
	centerText->textAlignment = UiText::TextAlignment::Center;
	centerText->textColor = ofColor(255, 255, 255);
}

void ScreenWelcome::onUpdate() {
	float timeLoopOffset = (float)(ofGetElapsedTimeMillis() % 3000) / 3000 * 2 * PI;	//	Calculate how far into the movement loop we are

	this->titleElement->yPosition = 40 + 10 * sinf(timeLoopOffset);	//	Make the title move a bit
	
	UiElement::onUpdate();	//	Update the child elements
}
bool ScreenWelcome::onClick(float x, float y) {
	ofApp::changeScreens(make_shared<ScreenDifficultySelect>());
	ofApp::changeScreens(make_shared<ScreenError>());
	return true;
}