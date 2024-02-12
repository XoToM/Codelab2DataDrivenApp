#include "ScreenGameOver.h"
#include <ofApp.h>
#include <ui/pokequiz/PokeTitle.h>
#include <string>
#include <ui/pokequiz/UiConstants.h>
#include <QuizGenerator.h>
#include <ui/UiBox.h>
#include <ui/UiButton.h>
#include <ui/UiElement.h>
#include <screens/ScreenWelcome.h>
#include <memory>

ScreenGameOver::ScreenGameOver() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(std::make_shared<PokeTitle>("Game Over", &ofApp::titleFont, &ofApp::titleHighlightFont));	//	Insert this screen's title

	auto questionFrame = this->addChild(UiBox::make_frame(0, POKEQUIZ_UI_MAIN_FRAME_TOP_OFFSET, 520, 200));
	questionFrame->centerHorizontallyOnScreen();
	questionFrame->addChild(make_shared<UiText>("Your score: " + std::to_string(QuizGenerator::mainGenerator->score),10,10,500))->textAlignment = UiText::TextAlignment::Center;
	auto optionBox = questionFrame->addChild(std::make_shared<UiElement>(15, 100, 480,100));
	optionBox->addChild(UiButton::makeButtonWithLabel("Main menu", 0, 0, []() {
		ofApp::changeScreens(std::make_shared<ScreenWelcome>());	//	Send the player back to the main menu
		}, &ofApp::smallFont, 200));

	optionBox->addChild(UiButton::makeButtonWithLabel("Retry", optionBox->width-200, 0, []() {

			QuizGenerator::mainGenerator = std::make_unique<QuizGenerator>(QuizGenerator::mainGenerator->pokemons, QuizGenerator::mainGenerator->difficulty);	//	Restart the quiz

			QuizGenerator::mainGenerator->generateNextQuestion();
			ofApp::changeScreens(QuizGenerator::mainGenerator->generateNextQuestion());
		}, &ofApp::smallFont, 200));
}