#pragma once

#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"
#include "screens/ScreenError.h"
#include <functional>

class UiButton : public virtual UiBox {
public:
	std::function<void()> onButtonClicked;

	UiButton(std::function<void()> onButtonClicked) : UiBox() {
		this->onButtonClicked = onButtonClicked;
	}

	bool onClicked(int button) {
		try {
			this->onButtonClicked();
		}
		catch (...) {	//	The button doesn't know what kind of error has occured, so it will just show a generic error screen.
			std::cout << "An error has occured somewhere in the program." << std::endl;
			ofApp::root->switchScreens(make_shared<ScreenError>());
		}
		return true;
	}
	bool isActive() {
		return isHoveredOver() && (UiRoot::isLeftMouseDown || UiRoot::isRightMouseDown);
	}
	void recalculateSize(float cw, float ch) {
		UiElement::recalculateSize(cw, ch);
	}
};