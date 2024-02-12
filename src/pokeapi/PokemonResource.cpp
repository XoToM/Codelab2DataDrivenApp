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

	std::string imageUrl;


	if (!ofApp::mainApp->imageCache.count(imageUrl)) {	//	If there isn't an image for this pokemon in the cache we should fetch a new one
		ofApp::mainApp->imageCache[imageUrl] = ofImage();
		ofLoadURLAsync(imageUrl, imageUrl);	//	Send the request to the api to fetch the pokemon image. Also pass in the url as the request's id so we can recognise it once the image has loaded.
	
	}


	this->pokemonName = readDefaultResourceName(speciesInfo["names"]);	//	Get the pokemon's name
	
}