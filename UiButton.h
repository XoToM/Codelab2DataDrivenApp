#pragma once

#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"
#include <functional>

//namespace PokeApp {
	//namespace Ui {
class UiButton : public UiElement {
public:
	UiButton() {
	}

	bool onRender(float parentX, float parentY) {
		float x = parentX + this->calculatedXPosition;
		float y = parentY + this->calculatedYPosition;
		ofColor randColor;
		randColor.setHsb(rand() % 360, 128, 128);
		ofColor altRandColor;
		altRandColor.setHsb(rand() % 360, 128, 128);

		ofSetColor(randColor);
		if (isPressed) ofSetColor(altRandColor);

		ofDrawRectangle(x, y, this->calculatedWidth, this->calculatedHeight);
		for (auto& child : this->Children) {
			child->onRender(x, y);
		}
		return true;
	}
	bool onClicked(int button) {
		return true;
	}
	void recalculateSize(float containerWidth, float containerHeight) {
		for (auto c : this->Children) {
			c->calculatedXPosition = calculatedXPosition;
			c->calculatedYPosition = calculatedYPosition;
			c->calculatedBoxWidth = calculatedBoxWidth;
			c->calculatedBoxHeight = calculatedBoxHeight;
			c->calculatedWidth = calculatedWidth;
			c->calculatedHeight = calculatedHeight;
			c->recalculateSize(containerWidth, containerHeight);
		}
	}
};
//}
//}
