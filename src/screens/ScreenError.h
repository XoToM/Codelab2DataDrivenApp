#pragma once
#include "ofApp.h"
#include "ui/UiBox.h"
#include "ui/UiText.h"

class ScreenError : public virtual UiBox
{
public:
	ScreenError() : UiBox(ElementOrientation::Vertical) {
		this->setMargins(20);
		this->addChild(make_shared<UiText>("Uh Oh... Something went wrong!", &ofApp::titleFont, 255, 180, 180, UiText::FontAlignment::Center));
		this->addChild(make_shared<UiText>("There was an unexpected problem with the program, and we had to stop what you were doing.\nYou might have to restart the program, and you will most likely lose progress if you already started a quiz.\nIt is possible that this was caused by a connection error, in which case you should try reconnecting to the internet before proceeding.", &ofApp::normalFont, 255, 255, 255, UiText::FontAlignment::Center));
	}
};

