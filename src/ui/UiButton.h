#pragma once

#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"
#include <functional>

//namespace PokeApp {
	//namespace Ui {
class UiButton : public virtual UiBox {
public:

	UiButton() : UiBox() {
	}

	bool onClicked(int button) {
		return true;
	}
	bool isActive() {
		return isHoveredOver() && UiRoot::isLeftMouseDown;
	}
	/*
	void recalculateSize(float containerWidth, float containerHeight) {
		defaultSpaceAllocator(containerWidth, containerHeight);
	}*/
};
//}
//}
