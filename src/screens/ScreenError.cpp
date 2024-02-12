#include "ScreenError.h"
#include "ScreenWelcome.h"
#include "ofApp.h"
#include "ui/pokequiz/UiConstants.h"

ScreenError::ScreenError() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<PokeTitle>("Uh Oh!", &ofApp::titleFont, &ofApp::titleHighlightFont));	//	Insert the error title
	auto frame = this->addChild(UiBox::make_frame(ofGetWidth() / 2 - 400, POKEQUIZ_UI_MAIN_FRAME_TOP_OFFSET, 800, 450));	//	Insert the main frame

	frame->addChild(make_shared<UiText>(
		"There was an error while connecting to PokeApi.\n\nPlease check your network connection. If this problem persists, it might be a problem with PokeApi.\n\n Click anywhere to go back to the title screen.",
		POKEQUIZ_UI_FRAME_MARGINS, POKEQUIZ_UI_FRAME_MARGIN_TOP, 800 - 2 * POKEQUIZ_UI_FRAME_MARGINS))
		->textAlignment = UiText::TextAlignment::Center;
}

bool ScreenError::onClick(float x, float y) {
	ofApp::changeScreens(make_shared<ScreenWelcome>());
	return true;
}