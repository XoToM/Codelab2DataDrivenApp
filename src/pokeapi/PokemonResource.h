#pragma once
#include <string>

class PokemonResource
{
	bool isLoaded = false;
	bool isValid = false;
public:
	std::string speciesUrl;
	std::string speciesName;
	std::string pokemonName;

	PokemonResource();
	PokemonResource(std::string speciesName, std::string speciesUrl);

	/// <summary>
	/// Fetches the info about the pokemon if it wasn't fetched yet.
	/// </summary>
	void fetch();
	
};

