#include "ScreenPokeQuestion.h"
#include <ofMain.h>
#include <ui/UiImage.h>

ScreenPokeQuestion::ScreenPokeQuestion(int questionNumber, std::string questionText, std::vector<std::string> answers, int correctIndex, std::string pokeImage) : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<UiImage>(pokeImage, 0, 0, 400, 400));
}