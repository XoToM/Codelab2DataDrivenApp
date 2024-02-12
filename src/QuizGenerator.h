#pragma once

#include "pokeapi/PokemonResource.h"
#include <map>
#include <memory>
#include <screens/ScreenPokeQuestion.h>

class QuizGenerator
{
private:
	std::shared_ptr<ScreenPokeQuestion> nextQuestion;
public:
	enum class QuizDifficulty { Easy, Normal, Hard };

	static std::unique_ptr<QuizGenerator> mainGenerator;

	QuizDifficulty difficulty;
	int questionCount = 1;
	int lives = 3;
	int score = 0;
	std::map<std::string, PokemonResource> pokemons;

	QuizGenerator(std::map<std::string, PokemonResource> pokemons, QuizDifficulty difficulty);
	QuizGenerator();

	std::shared_ptr<ScreenPokeQuestion> generateNextQuestion();
};

