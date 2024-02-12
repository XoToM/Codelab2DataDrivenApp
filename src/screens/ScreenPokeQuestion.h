#pragma once
#include "ui/UiElement.h"
#include <string>
#include "ofMain.h"

class ScreenPokeQuestion : public UiElement
{
public:
	static ofImage heartIconImage;

	ScreenPokeQuestion(int questionNumber, std::string questionText, std::vector<std::string> answers, int correctIndex, std::string pokeImage);
	void onRender(float x, float y);
};

