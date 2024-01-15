#pragma once
#include <stdlib.h>
#include "UiElement.h"

//namespace PokeApp {
	//namespace Ui {
template<class T> class UiPadding : public UiElement {
public:
	float upPad;
	float leftPad;
	float downPad;
	float rightPad;
	std::shared_ptr<T> child;



	UiPadding(std::shared_ptr<T> child, float up,float left=-1,float down=-1, float right=-1) {
		this->upPad = up;
		this->leftPad = left;
		this->downPad = down;
		this->rightPad = right;
		this->child = child;

		if (up < 0) up = 0;
		if (right < 0) right = up;
		if (down < 0) down = up;
		if (left < 0) left = right;

		this->requestedMinWidth = child->requestedMinWidth + right + left;
		this->requestedMinHeight = child->requestedMinHeight + up + down;
		if (this->requestedMaxWidth >= 0) this->requestedMaxWidth = child->requestedMaxWidth + right + left; else this->requestedMaxWidth = -1;
		if (this->requestedMaxHeight >= 0) this->requestedMaxHeight = child->requestedMaxHeight + up + down; else this->requestedMaxHeight = -1;
		this->growPoints = child->growPoints;
	}

	bool onRender(float parentX, float parentY) {
		auto left = this->leftPad;
		auto up = this->upPad;
		if (up < 0) up = 0;
		if (left < 0) left = up;
		return this->child->onRender(parentX+this->calculatedXPosition,parentY+this->calculatedYPosition);
	}
	bool onClicked(int button) {
		return this->child->onClicked(button);
	}
	bool onMousePressed(float x, float y, int button) {
		auto left = this->leftPad;
		auto up = this->upPad;
		if (up < 0) up = 0;
		if (left < 0) left = up;
		
		x -= left;
		y -= up;
		if (x < 0 || y < 0 || x>this->child->calculatedWidth || y>this->child->calculatedHeight) return false;

		return this->child->onMousePressed(x, y, button);
	}
	bool onMouseReleased(float x, float y, int button) {
		auto left = this->leftPad;
		auto up = this->upPad;
		if (up < 0) up = 0;
		if (left < 0) left = up;

		x -= left;
		y -= up;
		if (x < 0 || y < 0 || x>this->child->calculatedWidth || y>this->child->calculatedHeight) return false;

		return this->child->onMouseReleased(x, y, button);
	}
	void recalculateSize(float containerWidth, float containerHeight) {
		auto up = this->upPad;
		auto left = this->leftPad;
		auto down = this->downPad;
		auto right = this->rightPad;
		if (up < 0) up = 0;
		if (right < 0) right = up;
		if (down < 0) down = up;
		if (left < 0) left = right;

		this->requestedMinHeight = this->child->requestedMinHeight + up + down;
		this->requestedMinWidth = this->child->requestedMinWidth + left + right;
		if (this->requestedMaxHeight >= 0) this->requestedMaxHeight = this->child->requestedMaxHeight + up + down; else this->requestedMaxHeight = -1;
		if (this->requestedMaxWidth >= 0) this->requestedMaxWidth = this->child->requestedMaxWidth + left + right; else this->requestedMaxWidth = -1;
		this->growPoints = this->child->growPoints;

		this->child->calculatedWidth = this->calculatedWidth - left - right;
		this->child->calculatedHeight = this->calculatedHeight - up - down;
		this->child->calculatedXPosition = left;
		this->child->calculatedYPosition = up;

		this->child->recalculateSize(containerWidth-left-right,containerHeight-up-down);
	}
};
//}
//}
