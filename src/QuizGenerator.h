#pragma once

#include "pokeapi/PokemonResource.h"
#include <map>

class QuizGenerator
{
public:
	enum class QuizDifficulty { Easy, Normal, Hard };

	QuizDifficulty difficulty;
	int questionCount = 1;
	int lives = 3;

	QuizGenerator(std::map<std::string, PokemonResource> pokemons, QuizDifficulty difficulty) {
		this->difficulty = difficulty;
	}


};

