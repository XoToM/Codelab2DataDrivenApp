#include "PokemonResource.h"
#include "pokeapi/ApiErrors.h"
#include "ofxJson.h"
#include "ApiHelper.h"
#include <ofApp.h>

PokemonResource::PokemonResource(std::string speciesName, std::string speciesUrl) {
	this->speciesName = speciesName;
	this->speciesUrl = speciesUrl;
	this->isValid = true;
}
PokemonResource::PokemonResource() {
	this->isValid = false;
}

void PokemonResource::fetch() {
	if (!this->isValid || this->isLoaded) return;
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

	if (pokemonInfo["sprites"]["other"]["front_default"].isString()) {		//	Try fetching the official artwork image for this pokemon
		this->imageUrl = pokemonInfo["sprites"]["other"]["front_default"].asString();
	}
	else if(pokemonInfo["sprites"]["front_default"].isString()){		//	If we cannot fetch the official artwork for this pokemon we should fall back to the default sprite for it
		this->imageUrl = pokemonInfo["sprites"]["front_default"].asString();
	}
	else {
		throw POKEAPI_JSON_EXCEPTION;	//	Most likely the json data we got is in an invalid format
	}


	if (!ofApp::mainApp->imageCache.count(this->imageUrl)) {	//	If there isn't an image for this pokemon in the cache we should fetch a new one
		ofApp::mainApp->imageCache[this->imageUrl] = ofImage();
		ofLoadURLAsync(this->imageUrl, this->imageUrl);	//	Send the request to the api to fetch the pokemon image. Also pass in the url as the request's id so we can recognise it once the image has loaded.
	}


	this->pokemonName = readDefaultResourceName(speciesInfo["names"]);	//	Get the pokemon's name
	
}