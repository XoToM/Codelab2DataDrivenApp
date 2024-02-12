#pragma once
#include "ofxJson.h"

/// <summary>
/// Reads through the list of names and returns the English name from the list. If an English name could not be found returns the first name it can.
/// </summary>
/// <param name="namedResource"></param>
/// <returns>Returns the English name. If an English name cannot be found returns the first available name.</returns>
std::string readDefaultResourceName(ofxJSONElement namedResource);



/// <summary>
/// Fetches the list of the Pokemon game generations from PokeApi
/// </summary>
/// <returns>The list of the Pokemon game generations. The tuple contains the Generation's name (in English) and generation's info.</returns>
std::vector<std::tuple<std::string, ofxJSONElement>> fetchGenerationList();