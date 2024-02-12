#include "ScreenError.h"
#include "ScreenWelcome.h"
#include "ofApp.h"

ScreenError::ScreenError() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<PokeTitle>("Uh Oh!", &ofApp::titleFont, &ofApp::titleHighlightFont));
	auto frame = this->addChild(UiBox::make_frame(ofGetWidth() / 2 - 400, ofGetHeight() / 2 - 150, 800, 450));

	frame->addChild(make_shared<UiText>(
		"There was an error while connecting to PokeApi.\n\nPlease check your network connection. If this problem persists, it might be a problem with PokeApi.\n\n Click anywhere to go back to the title screen.",
		20, 20, 760))
		->textAlignment = UiText::TextAlignment::Center;
}

bool ScreenError::onClick(float x, float y) {
	ofApp::changeScreens(make_shared<ScreenWelcome>());
	return true;
}