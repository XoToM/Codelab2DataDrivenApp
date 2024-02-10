#pragma once

#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"
#include <functional>

//namespace PokeApp {
	//namespace Ui {
class UiButton : public virtual UiElement {
public:
	UiButton() : UiElement() {
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
	/*
	void recalculateSize(float containerWidth, float containerHeight) {
		defaultSpaceAllocator(containerWidth, containerHeight);
	}*/
};
//}
//}
