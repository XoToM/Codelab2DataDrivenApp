#pragma once
#include <stdlib.h>
#include "UiElement.h"

class UiSpace : public virtual UiElement {
public:
	UiSpace(float minWidth = 0, int widthGrow = 1, float maxWidth = -1) : UiElement() {
		this->minWidth = minWidth;
		this->maxWidth = maxWidth;
		this->growFactor = widthGrow;
	}

	bool onRender(float parentX, float parentY) {
		return true;
	}
	void recalculateSize(float containerWidth, float containerHeight) {}
};