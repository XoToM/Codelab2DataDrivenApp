#include "QuizGenerator.h"
#include <ofMath.h>


std::unique_ptr<QuizGenerator> QuizGenerator::mainGenerator;

QuizGenerator::QuizGenerator() {
	this->difficulty = QuizDifficulty::Normal;
}

QuizGenerator::QuizGenerator(std::map<std::string, PokemonResource> pokemons, QuizDifficulty difficulty) {
	this->difficulty = difficulty;
	this->pokemons = pokemons;
	this->generateNextQuestion();

}
std::shared_ptr<ScreenPokeQuestion> QuizGenerator::generateNextQuestion() {
	
	int pokemonIndex = (int)std::floor(ofRandom(this->pokemons.size()));

	auto mapIterator = this->pokemons.begin();		//	std::map isn't designed to be accessed by index as its elements are not ordered, however here we want to get a random element in the map, so we don't care about order. 
	std::advance(mapIterator,pokemonIndex);		//	This means we can just create an iterator over the map's items, and advance it by a random amount of steps to get the random element.
	
	PokemonResource* pokemonInfo = &mapIterator->second;

	pokemonInfo->fetch();

	std::shared_ptr<ScreenPokeQuestion> question = std::make_shared<ScreenPokeQuestion>(this->questionCount++, "WHo's that pokemon?", std::vector<std::string>(), 0, pokemonInfo->imageUrl);

	auto oldQuestion = this->nextQuestion;
	this->nextQuestion = question;
	return oldQuestion;
}