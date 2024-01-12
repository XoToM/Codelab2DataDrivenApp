#pragma once
#include <stdlib.h>
#include "UiElement.h"

//namespace PokeApp {
	//namespace Ui {
template<class T> class UiPadding : public UiElement {
public:
	UiPadding(T child) {
		this->requestedMinWidth = minWidth;
		this->requestedMaxWidth = maxWidth;
		this->growPoints = widthGrow;
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
