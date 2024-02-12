#include "ScreenDifficultySelect.h"
#include <ui/UiButton.h>

ScreenDifficultySelect::ScreenDifficultySelect() : UiBox(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(UiButton::makeButtonWithLabel("Test Button", 50, 50, []() {cout << "Test" << endl; }));
}