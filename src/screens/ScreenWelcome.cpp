#include "ScreenWelcome.h"
#include "../ui/UiText.h"
#include "ofApp.h"

ScreenWelcome::ScreenWelcome() : UiBox(0, 0, ofGetWidth(), ofGetHeight()) {
	this->addChild(make_shared<UiText>("Hello, World!", &ofApp::titleFont, 50, 50));
	this->addChild(make_shared<UiText>("This text is very very very very very very very very long", &ofApp::titleFont, 50, 100, 300))->textAlignment = UiText::TextAlignment::Center;
}