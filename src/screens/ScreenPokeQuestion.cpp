#include "screens/ScreenPokeQuestion.h"
#include <ofMain.h>
#include <ui/UiImage.h>
#include "ui/pokequiz/PokeTitle.h"
#include "ui/UiBox.h"
#include "ui/pokequiz/UiConstants.h"
#include "ofApp.h"
#include <QuizGenerator.h>
#include <ui/UiButton.h>

ScreenPokeQuestion::ScreenPokeQuestion(int questionNumber, std::string questionText, std::vector<std::string> answers, int correctIndex, std::string pokeImageName) : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<PokeTitle>("Question " + std::to_string(questionNumber), &ofApp::titleFont, &ofApp::titleHighlightFont));	//	Insert this screen's title
	
	auto questionFrame = this->addChild(UiBox::make_frame(0, POKEQUIZ_UI_MAIN_FRAME_TOP_OFFSET-80,800,300));
	questionFrame->centerHorizontallyOnScreen();
	auto qaLabel = questionFrame->addChild(make_shared<UiText>("Who's that Pokemon?", 310, 150-ofApp::normalFont.getLineHeight(), 480));
	qaLabel->textAlignment = UiText::TextAlignment::Center;

	std::string correctAnsewr = answers[correctIndex];

	auto pokeImage = questionFrame->addChild(make_shared<UiImage>(pokeImageName, 10, 10, 280, 280));

	if (QuizGenerator::mainGenerator->difficulty != QuizGenerator::QuizDifficulty::Easy) {
		pokeImage->blindImage = true;	//	Make the game slightly harder on normal and above by hidding the image
	}

	auto optionsBox = this->addChild(UiBox::make_frame(0, ofGetHeight()-50-200, 920, 200));	//	Create a container for all the buttons
	optionsBox->centerHorizontallyOnScreen();

	//	Generate the buttons for each generation
	for (int i = 0; i < answers.size(); i++) {

		//	Generate a button for each generation and make them wrap around the optionsBox, effectively creating a grid of buttons
		optionsBox->addChild(UiButton::makeButtonWithLabel(answers[i], (i % 3) * 300+10, (i / 3) * (ofApp::normalFont.getLineHeight() + 30)+30, [i, correctIndex, optionsBox, pokeImage, qaLabel, correctAnsewr]() {

			pokeImage->blindImage = false;
			if (i == correctIndex) {
				qaLabel->text = "Thats Right! This is a " + correctAnsewr;
			}
			else {
				qaLabel->text = "Wrong! This is a " + correctAnsewr;
			}
			qaLabel->updateWordWrapping();

			optionsBox->Children.clear();
			optionsBox->addChild(UiButton::makeButtonWithLabel("Next Question", 0, 100, []() {
				ofApp::changeScreens(QuizGenerator::mainGenerator->generateNextQuestion());
				}))->centerHorizontallyInParent(optionsBox);


			}, &ofApp::smallFont, 250));
	}
}