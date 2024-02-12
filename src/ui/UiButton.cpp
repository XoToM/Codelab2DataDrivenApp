#include "UiButton.h"
#include "UiText.h"
#include <ofApp.h>

UiButton::UiButton(float x, float y, float width, float height, std::function<void()> onClickHandler) : UiBox(x, y, width, height) {
	this->onClickHandler = onClickHandler;
}
std::shared_ptr<UiButton> UiButton::makeButtonWithLabel(std::string text, float x, float y, std::function<void()> onClickHandler, float width) {
	auto font = &ofApp::normalFont;
	auto textBbox = font->getStringBoundingBox(text,0,0);

	if (width < 0) width = textBbox.getWidth() + 20;

	auto button = make_shared<UiButton>(x, y, width, textBbox.getHeight() + 10, onClickHandler);
	button->fillColor = ofColor(255, 255, 255);

	auto label = button->addChild(make_shared<UiText>(text, font, 5, 5, width - 10));
	label->doWordWrapping = false;
	label->textAlignment = UiText::TextAlignment::Center;
	label->updateWordWrapping();

	return button;
}

ofColor UiButton::getFillColor() {
	if (this->isHoveredOver()) {
		if (ofApp::mainApp->isLeftMousePressed) {
			return this->clickColor;
		}
		else {
			return this->hoverColor;
		}
	}
	return this->fillColor;
}

bool UiButton::onClick(float x, float y) {
	onClickHandler();
	return true;
}