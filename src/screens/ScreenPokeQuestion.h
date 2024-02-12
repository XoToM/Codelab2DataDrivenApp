#pragma once
#include "ui/UiElement.h"
#include <string>

class ScreenPokeQuestion : public UiElement
{
public:

	ScreenPokeQuestion(int questionNumber, std::string questionText, std::vector<std::string> answers, int correctIndex, std::string pokeImage);
};

