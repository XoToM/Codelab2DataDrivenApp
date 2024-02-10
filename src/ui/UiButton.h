#pragma once

#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"
#include <functional>

class UiButton : public virtual UiBox {
public:
	std::function<void()> onButtonClicked;

	UiButton(std::function<void()> onButtonClicked) : UiBox() {
		this->onButtonClicked = onButtonClicked;
	}

	bool onClicked(int button) {
		this->onButtonClicked();
		return true;
	}
	bool isActive() {
		return isHoveredOver() && (UiRoot::isLeftMouseDown || UiRoot::isRightMouseDown);
	}
};