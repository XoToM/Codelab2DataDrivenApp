#include "screens/ScreenPokeQuestion.h"
#include <ofMain.h>
#include <ui/UiImage.h>
#include "ui/pokequiz/PokeTitle.h"
#include "ui/UiBox.h"
#include "ui/pokequiz/UiConstants.h"
#include "ofApp.h"
#include <QuizGenerator.h>
#include <ui/UiButton.h>
#include "ScreenGameOver.h"

ofImage ScreenPokeQuestion::heartIconImage;

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
				qaLabel->text = "Thats Right! It's " + correctAnsewr;
				QuizGenerator::mainGenerator->score++;
				if (QuizGenerator::mainGenerator->streak++ >= 2) {
					QuizGenerator::mainGenerator->streak -= 3;

					QuizGenerator::mainGenerator->lives = std::min(QuizGenerator::mainGenerator->lives+1, QuizGenerator::mainGenerator->maxLives);
				}
			}
			else {
				qaLabel->text = "Wrong! It's " + correctAnsewr;
				QuizGenerator::mainGenerator->lives--;
				QuizGenerator::mainGenerator->streak = 0;
				if (QuizGenerator::mainGenerator->lives <= 0) {
					ofApp::changeScreens(std::make_shared<ScreenGameOver>());
					return;
				}
			}
			qaLabel->updateWordWrapping();

			optionsBox->Children.clear();
			optionsBox->addChild(UiButton::makeButtonWithLabel("Next Question", 0, 100, []() {
				ofApp::changeScreens(QuizGenerator::mainGenerator->generateNextQuestion());
				}))->centerHorizontallyInParent(optionsBox);


			}, &ofApp::smallFont, 250));
	}
}
void ScreenPokeQuestion::onRender(float x, float y) {
	UiElement::onRender(x, y);	//	Render the ui first

	if (!ScreenPokeQuestion::heartIconImage.isAllocated()) {	//	Render the extra stuff like hearts
		ScreenPokeQuestion::heartIconImage.loadImage("images/heart.png");	//	Heart graphics made by me
	}
	ofSetColor(255, 255, 255);
	for (int i = 0; i < QuizGenerator::mainGenerator->lives; i++) {
		heartIconImage.draw((float)(10 + x + i * 72), (float)(10 + y), 64, 64);
	}
}