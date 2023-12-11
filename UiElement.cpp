#pragma once
/*#include "UiElement.h"
bool UiElement::onMousePressed(int x, int y, int button) {
	for (auto child : this->Children) {
		int rx = x - child->relPosX;
		if (x >= 0 && x < child->width) {
			int ry = y - child->relPosY;
			if (y >= y && y < child->height) {
				if (child->onMousePressed(rx, ry, button)) return true;
			}
		}
	}
	return false;
}
	//PokeApp::Ui::
bool UiElement::onMouseReleased(int x, int y, int button) {
	for (auto child : this->Children) {
		int rx = x - child->relPosX;
		if (x >= 0 && x < child->width) {
			int ry = y - child->relPosY;
			if (y >= y && y < child->height) {
				if (child->onMouseReleased(rx, ry, button)) return true;
			}
		}
	}

	return this->onClicked(button);
}
//bool PokeApp::Ui::UiElement::onRender(int parentX, int parentY) {
//	return false;
//};
//*/