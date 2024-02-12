#include "ScreenDifficultySelect.h"
#include "ui/UiButton.h"
#include "ofApp.h"
#include "ScreenWelcome.h"
#include "ui/pokequiz/PokeTitle.h"
#include "ui/UiText.h"
#include "ui/pokequiz/UiConstants.h"
#include "ScreenGenerationSelect.h"
#include "QuizGenerator.h"

ScreenDifficultySelect::ScreenDifficultySelect() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<PokeTitle>("Select the difficulty", &ofApp::titleFont, &ofApp::titleHighlightFont));	//	Insert this screen's title

	auto box = this->addChild(UiBox::make_frame(0, POKEQUIZ_UI_MAIN_FRAME_TOP_OFFSET, 600, 300));	//	Create the main frame
	box->centerHorizontallyOnScreen();
	box->addChild(make_shared<UiText>("Please select the difficulty of the quiz.", POKEQUIZ_UI_FRAME_MARGINS + 10, POKEQUIZ_UI_FRAME_MARGINS, 600 - 2 * POKEQUIZ_UI_FRAME_MARGINS -20));

	auto optionsBox = box->addChild(make_shared<UiElement>(0, 200, 550, 300));
	optionsBox->centerHorizontallyInParent(box);

	//	Add the difficulty settings buttons
	optionsBox->addChild(UiButton::makeButtonWithLabel("Easy", 0, 0, []() {
			ofApp::changeScreens(make_shared<ScreenGenerationSelect>(QuizGenerator::QuizDifficulty::Easy));
		}, & ofApp::smallFont, 150));
	optionsBox->addChild(UiButton::makeButtonWithLabel("Normal", 200, 0, []() {
			ofApp::changeScreens(make_shared<ScreenGenerationSelect>(QuizGenerator::QuizDifficulty::Normal));
		}, & ofApp::smallFont, 150));
	optionsBox->addChild(UiButton::makeButtonWithLabel("Hard", 400, 0, []() {
			ofApp::changeScreens(make_shared<ScreenGenerationSelect>(QuizGenerator::QuizDifficulty::Hard));
		}, & ofApp::smallFont, 150));

	//	Create a frame for the back button
	auto backFrame = this->addChild(UiBox::make_frame(0, ofGetHeight() - POKEQUIZ_UI_BOTTOM_BUTTONS_BOTTOM_OFFSET, POKEQUIZ_UI_SMALL_FRAME_WIDTH, ofApp::normalFont.getLineHeight() + 2 * POKEQUIZ_UI_FRAME_MARGINS));
	backFrame->centerHorizontallyOnScreen();
	backFrame->addChild(UiButton::makeButtonWithLabel("Back", POKEQUIZ_UI_FRAME_MARGINS, POKEQUIZ_UI_FRAME_MARGIN_TOP, []() { 	//	Insert the back button at the bottom of the frame
		ofApp::changeScreens(std::make_shared<ScreenWelcome>()); 
		}, &ofApp::smallFont))->centerHorizontallyInParent(backFrame);
}