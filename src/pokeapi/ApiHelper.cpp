#include "ApiHelper.h"
#include "ofApp.h"
#include "pokeapi/ApiErrors.h"

std::string readDefaultResourceName(ofxJSONElement namedResource) {
	if(namedResource.isNull()) throw POKEAPI_JSON_EXCEPTION;	//	Make sure we received a valid piece of data to work with

	for (int i = 0; i < namedResource.size(); i++) {
		auto nameInfo = namedResource[i];
		if (nameInfo["language"]["name"] == "en") return nameInfo["name"].asString();	//	If this name is in English we should return it. 
	}
	return namedResource[0]["name"].asString();	//	If we couldn't find the english name we should return the first name we can. Most likely this is going to be the japanese name.
}

std::vector<std::tuple<std::string, ofxJSONElement>> fetchGenerationList() {
	ofxJSONElement generations;
	if (!generations.openRemote("https://pokeapi.co/api/v2/generation/?limit=9")) throw POKEAPI_NETWORK_EXCEPTION;	//	Fetch the list of game generations from PokeApi. Only fetch the first 9 generations because thats how many we have right now, and we might have problems displaying more.
	
	generations = generations["results"];	//	Make sure the data is in the correct format
	if (generations.isNull()) throw POKEAPI_JSON_EXCEPTION;

	std::vector<std::tuple<std::string, ofxJSONElement>> generationList;

	for (int i = 0; i < generations.size(); i++) {	//	Loop over every generation and fetch the data for each one
		ofxJSONElement generationInfo;

		if(!generationInfo.openRemote(generations[i]["url"].asString())) throw POKEAPI_NETWORK_EXCEPTION;

		std::string generationName = readDefaultResourceName(generationInfo["names"]);	//	Read the name and add the generation to the list
		generationList.push_back(make_tuple(generationName, generationInfo));
	}

	return generationList;
}