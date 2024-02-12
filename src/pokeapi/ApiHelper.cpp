#include "ApiHelper.h"

std::string readDefaultResourceName(ofxJSONElement namedResource) {
	for (int i = 0; i < namedResource.size(); i++) {
		auto nameInfo = namedResource[i];
		if (nameInfo["language"]["name"] == "en") return namedResource["name"].asString();	//	If this name is in English we should return it. 
	}
	return namedResource[0]["name"].asString();	//	If we couldn't find the english name we should return the first name we can. Most likely this is going to be the japanese name.
}

std::vector<std::string> fetchGenerationList() {
	ofxJSONElement generations;
	generations.openRemote("https://pokeapi.co/api/v2/generation/");
	return std::vector<std::string>();
}