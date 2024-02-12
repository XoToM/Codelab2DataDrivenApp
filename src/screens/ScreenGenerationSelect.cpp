#include "ScreenGenerationSelect.h"
#include "ScreenDifficultySelect.h"
#include "ui/UiButton.h"
#include "ofApp.h"
#include "ui/pokequiz/PokeTitle.h"
#include "ui/UiText.h"
#include "ui/pokequiz/UiConstants.h"
#include "QuizGenerator.h"
#include <pokeapi/ApiHelper.h>
#include <pokeapi/ApiErrors.h>
#include <pokeapi/PokemonResource.h>


void collectPokemons(std::map<std::string, PokemonResource>* pokemons, ofxJSONElement generation) {
	auto species = generation["pokemon_species"];
	if (species.isNull()) throw POKEAPI_JSON_EXCEPTION;	//	Throw an error if the data we got from the api is in an unknown format

	for (int i = 0; i < species.size(); i++) {
		auto pokemon = species[i];

		std::string speciesName = pokemon["name"].asString();
		(*pokemons)[speciesName] = PokemonResource(speciesName, pokemon["url"].asString());	//	Insert the pokemon resource into the pokemon list
	}
}

ScreenGenerationSelect::ScreenGenerationSelect(QuizGenerator::QuizDifficulty difficulty) : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<PokeTitle>("Select the Games", &ofApp::titleFont, &ofApp::titleHighlightFont));	//	Insert this screen's title

	auto box = this->addChild(UiBox::make_frame(0, POKEQUIZ_UI_MAIN_FRAME_TOP_OFFSET, 900, 320));	//	Create the main frame
	box->centerHorizontallyOnScreen();
	box->addChild(make_shared<UiText>("Please select the games for your quiz.", POKEQUIZ_UI_FRAME_MARGINS + 10, POKEQUIZ_UI_FRAME_MARGINS, 900 - 2 * POKEQUIZ_UI_FRAME_MARGINS - 20));

	auto gameGenerations = fetchGenerationList();	//	Fetch all the different pokemon generations

	auto optionsBox = box->addChild(make_shared<UiElement>(0, 100, 890, 300));	//	Create a container for all the buttons
	optionsBox->centerHorizontallyInParent(box);

	//	Generate the buttons for each generation
	for (int i = 0; i < gameGenerations.size(); i++) {
		auto generationName = std::get<0>(gameGenerations[i]);
		auto generationInfo = std::get<1>(gameGenerations[i]);

		//	Generate a button for each generation and make them wrap around the optionsBox, effectively creating a grid of buttons
		optionsBox->addChild(UiButton::makeButtonWithLabel(generationName, (i % 3) * 310, (i / 3) * (ofApp::normalFont.getLineHeight() + 30), [generationInfo, difficulty]() {
			std::map<std::string, PokemonResource> pokemons;	//	A map is used here to avoid duplicate pokemon entries.
			collectPokemons(&pokemons, generationInfo);	//	Add the pokemon into the list of all the pokemon the quiz can ask questions about.

			QuizGenerator::mainGenerator = std::make_unique<QuizGenerator>(pokemons, difficulty);

			ofApp::changeScreens(QuizGenerator::mainGenerator->generateNextQuestion());

			}, &ofApp::smallFont, 270));
	}


	//	Create a frame for the back button
	auto backFrame = this->addChild(UiBox::make_frame(0, ofGetHeight() - POKEQUIZ_UI_BOTTOM_BUTTONS_BOTTOM_OFFSET, POKEQUIZ_UI_SMALL_FRAME_WIDTH, ofApp::normalFont.getLineHeight() + 2 * POKEQUIZ_UI_FRAME_MARGINS));
	backFrame->centerHorizontallyOnScreen();
	backFrame->addChild(UiButton::makeButtonWithLabel("Back", POKEQUIZ_UI_FRAME_MARGINS, POKEQUIZ_UI_FRAME_MARGIN_TOP, []() { 	//	Insert the back button at the bottom of the frame
		ofApp::changeScreens(std::make_shared<ScreenDifficultySelect>());
		}))->centerHorizontallyInParent(backFrame);
}