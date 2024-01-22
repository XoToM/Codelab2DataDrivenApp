#pragma once
#include <stdlib.h>
#include "UiElement.h"
#include "ResourceManager.h"

//namespace PokeApp {
	//namespace Ui {
class UiText : public UiElement {
public:
	string text;
	UiText(string text) {
		ResourceManager::InitResourceManager();
		this->text = text;
	}

	bool onRender(float parentX, float parentY) {
		ResourceManager::getDefaultFont().drawString("test", calculatedXPosition, calculatedYPosition);
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
