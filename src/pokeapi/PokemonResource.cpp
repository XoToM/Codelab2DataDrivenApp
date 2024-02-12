#include "PokemonResource.h"
#include "pokeapi/ApiErrors.h"
#include "ofxJson.h"
#include "ApiHelper.h"

PokemonResource::PokemonResource(std::string speciesName, std::string speciesUrl) {
	this->speciesName = speciesName;
	this->speciesUrl = speciesUrl;
}

void PokemonResource::fetch() {
	if (this->isLoaded) return;
	isLoaded = true;

	ofxJSONElement speciesInfo;
	ofxJSONElement pokemonInfo;


	if (!speciesInfo.openRemote(this->speciesUrl)) throw POKEAPI_NETWORK_EXCEPTION;	//	Fetch info about the species of this pokemon

	auto speciesVarieties = speciesInfo["varieties"];

	std::string pokemonInfoLink = speciesVarieties[0]["pokemon"]["url"].asString();		//	Get the link to the default pokemon variation referenced by this species.
	for (int i = 0; i < speciesVarieties.size(); i++) {
		if (speciesVarieties[i]["is_default"].asBool()) {		//	Check if this variation is the default one
			pokemonInfoLink = speciesVarieties[i]["pokemon"]["url"].asString();
			break;
		}
	}

	if (!pokemonInfo.openRemote(pokemonInfoLink)) throw POKEAPI_NETWORK_EXCEPTION;	//	Fetch info about this pokemon


	this->pokemonName = readDefaultResourceName(speciesInfo["names"]);	//	Get the pokemon's name
}