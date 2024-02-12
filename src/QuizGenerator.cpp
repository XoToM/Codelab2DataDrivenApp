#include "QuizGenerator.h"
#include <ofMath.h>
#include <ofApp.h>


std::unique_ptr<QuizGenerator> QuizGenerator::mainGenerator;

QuizGenerator::QuizGenerator() {
	this->difficulty = QuizDifficulty::Normal;
}

QuizGenerator::QuizGenerator(std::map<std::string, PokemonResource> pokemons, QuizDifficulty difficulty) {
	this->difficulty = difficulty;
	this->pokemons = pokemons;
	this->maxLives = 3;
	this->score = 0;
	if (difficulty == QuizDifficulty::Hard) this->maxLives = 1;
	this->lives = this->maxLives;

}
std::shared_ptr<ScreenPokeQuestion> QuizGenerator::generateNextQuestion() {
	auto answers = std::vector<std::string>();
	int correct = (int)std::floor(ofRandom(4));		//	Determine which pokemon will be the correct one

	std::string correctImageUrl;

	for (int i = 0; i < 6; i++) {
		int pokemonIndex = (int)std::floor(ofRandom(this->pokemons.size()));

		auto mapIterator = this->pokemons.begin();		//	std::map isn't designed to be accessed by index as its elements are not ordered, however here we want to get a random element in the map, so we don't care about order. 
		std::advance(mapIterator, pokemonIndex);		//	This means we can just create an iterator over the map's items, and advance it by a random amount of steps to get the random element.

		PokemonResource* pokemonInfo = &mapIterator->second;

		pokemonInfo->fetch();

		bool uniqueCheckFailed = false;	//	Check if this pokemon already exists in the answers list
		for (auto prevAns : answers) {
			if (prevAns == pokemonInfo->pokemonName) {
				uniqueCheckFailed = true;
				break;
			}
		}
		if (uniqueCheckFailed) {
			i--;	//	Decrement i. It will be incremented again on the next iteration of the loop, meaning that this effectively forces this iteration of the loop to restart.
			std::cout << "Reroll" << std::endl;
			continue;
		}

		answers.push_back(pokemonInfo->pokemonName);
		if (i == correct) correctImageUrl = pokemonInfo->imageUrl;
	}
	
	std::cout << "The correct answer is " << answers[correct] << std::endl;

	std::shared_ptr<ScreenPokeQuestion> question = std::make_shared<ScreenPokeQuestion>(this->questionCount++, "Who's that pokemon?", answers, correct, correctImageUrl);


	auto oldQuestion = this->nextQuestion;
	this->nextQuestion = question;
	return oldQuestion;
}