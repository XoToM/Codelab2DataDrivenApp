#include "UiBox.h"
#include <ofGraphics.h>

void UiBox::onRender(float x, float y) {
	ofSetColor(this->getFillColor());
	if (this->borderRadius > 0) {
		ofRectRounded(x, y, this->width, this->height, this->borderRadius);
	}
	else {
		ofDrawRectangle(x, y, this->width, this->height);
	}

	UiElement::onRender(x, y);	//	Call onRender on this element's children
}
ofColor UiBox::getFillColor() {
	return this->fillColor;
}
UiBox::UiBox(float x, float y, float width, float height) : UiElement(x, y, width, height) {}