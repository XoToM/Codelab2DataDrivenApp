#include "screens/ScreenPokeQuestion.h"
#include <ofMain.h>
#include <ui/UiImage.h>
#include "ui/pokequiz/PokeTitle.h"
#include "ui/UiBox.h"
#include "ui/pokequiz/UiConstants.h"
#include "ofApp.h"

ScreenPokeQuestion::ScreenPokeQuestion(int questionNumber, std::string questionText, std::vector<std::string> answers, int correctIndex, std::string pokeImage) : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<PokeTitle>("Question " + questionNumber, &ofApp::titleFont, &ofApp::titleHighlightFont));	//	Insert this screen's title
	
	auto questionFrame = this->addChild(UiBox::make_frame(0, POKEQUIZ_UI_MAIN_FRAME_TOP_OFFSET,400,400));
	this->addChild(make_shared<UiImage>(pokeImage, 0, 0, 400, 400));


}