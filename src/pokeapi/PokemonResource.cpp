#include "PokemonResource.h"
#include "pokeapi/ApiErrors.h"
#include "ofxJson.h"
#include "ApiHelper.h"
#include <ofApp.h>

PokemonResource::PokemonResource(std::string speciesName, std::string speciesUrl) {
	this->speciesName = speciesName;
	this->speciesUrl = speciesUrl;
	this->isValid = true;
	this->isLoaded = false;
}
PokemonResource::PokemonResource() {
	this->isValid = false;
	this->isLoaded = false;
}

void PokemonResource::fetch() {
	if (!this->isValid || this->isLoaded) return;
	isLoaded = true;

	ofxJSONElement speciesInfo;
	ofxJSONElement pokemonInfo;


	if (!speciesInfo.openRemote(this->speciesUrl)) {
		cout << "Nice throw!" << endl; throw POKEAPI_NETWORK_EXCEPTION;
	}	//	Fetch info about the species of this pokemon

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


	if (pokemonInfo["sprites"]["other"]["official-artwork"]["front_default"].isString()) {		//	Try fetching the official artwork image for this pokemon
		this->imageUrl = pokemonInfo["sprites"]["other"]["official-artwork"]["front_default"].asString();
		cout << "Main image for " << this->pokemonName << endl;
	}
	else if(pokemonInfo["sprites"]["front_default"].isString()){		//	If we cannot fetch the official artwork for this pokemon we should fall back to the default sprite for it
		cout << "Backup image for " << this->pokemonName << endl;
		this->imageUrl = pokemonInfo["sprites"]["front_default"].asString();
	}
	else {
		throw POKEAPI_JSON_EXCEPTION;	//	Most likely the json data we got is in an invalid format
	}

	if (!ofApp::mainApp->imageCache.count(this->imageUrl)) {	//	If there isn't an image for this pokemon in the cache we should fetch a new one
		ofImage img;
		auto response = ofLoadURL(this->imageUrl);
		img.load(response);		//	Fetch the image from the api
		ofApp::mainApp->imageCache[this->imageUrl] = img;
	}


	
}