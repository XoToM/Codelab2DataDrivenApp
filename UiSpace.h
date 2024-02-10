#pragma once
#include <stdlib.h>
#include "UiElement.h"

//namespace PokeApp {
	//namespace Ui {
class UiSpace : public UiElement {
public:
	UiSpace(float minWidth = 0, int widthGrow = 1, float maxWidth = -1) {
		this->minWidth = minWidth;
		this->maxWidth = maxWidth;
		this->growFactor = widthGrow;
	}

	bool onRender(float parentX, float parentY) {
		return true;
	}
	bool onClicked(int button) {
		return false;
	}
	bool onMousePressed(float x, float y, int button) {
		return false;
	}
	bool onMouseReleased(float x, float y, int button) {
		return false;
	}
	void recalculateSize(float containerWidth, float containerHeight) {}
};
//}
//}
