#include "ScreenDifficultySelect.h"
#include <ui/UiButton.h>

ScreenDifficultySelect::ScreenDifficultySelect() : UiElement(0, 0, ofGetWidth(), ofGetHeight()) {
	auto box = this->addChild(UiBox::make_frame(100,500,600,300));
	box->addChild(UiButton::makeButtonWithLabel("Test Button", 50, 50, []() { cout << "Test" << endl; }));
}