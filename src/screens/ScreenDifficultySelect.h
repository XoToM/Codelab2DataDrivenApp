#pragma once
#include <ui/UiBox.h>
#include <ui/UiText.h>
#include <ofApp.h>
#include <ui/UiSpace.h>
#include <ui/UiButton.h>
class ScreenDifficultySelect : public virtual UiBox
{
public:
	ScreenDifficultySelect(): UiBox(ElementOrientation::Vertical) {
		this->setMargins(20);
		this->addChild(make_shared<UiText>("Select the difficulty", &ofApp::titleFont, 255, 255, 255, UiText::FontAlignment::Center));
		this->addChild(make_shared<UiSpace>());

		auto optionList = this->addChild(make_shared<UiBox>(ElementOrientation::Vertical));
		//auto option = optionList->addChild(make_shared<UiButton>([]() {  }));
		optionList->setMargins(10);

		this->addChild(make_shared<UiSpace>(0,2));
		auto submitButton = make_shared<UiButton>([]() { });
		submitButton->addChild(UiBox::createCenteredElement(make_shared<UiText>("Start Quiz", &ofApp::subTitleFont,255,255,255,UiText::FontAlignment::Center),ElementOrientation::Vertical));
		submitButton->defaultColor = ofColor(255,0,0);
		submitButton->hoverColor = ofColor(0,0,255);
		submitButton->activeColor = ofColor(0,255,0);
		submitButton->minWidth = 220;
		submitButton->minHeight = 110;
		submitButton->maxHeight = 130;
		this->addChild(UiBox::createCenteredElement<UiButton>(submitButton, ElementOrientation::Horizontal));
		submitButton->onButtonClicked = [submitButton]() { cout << submitButton->calculatedBoxWidth << " " << submitButton->calculatedBoxHeight << endl; };
		this->addChild(make_shared<UiSpace>());
	}
};

