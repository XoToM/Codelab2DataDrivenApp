#include "UiButton.h"
#include "UiText.h"
#include <ofApp.h>

UiButton::UiButton(float x, float y, float width, float height) : UiBox(x, y, width, height) {
}
std::shared_ptr<UiButton> UiButton::makeButtonWithLabel(std::string text, float x, float y, float width, float height) {
	auto button = make_shared<UiButton>(x,y,width,height);
	button->addChild(make_shared<UiText>(text, &ofApp::normalFont, 5, 5, width - 10));

	return button;
}