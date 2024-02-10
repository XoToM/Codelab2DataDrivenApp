#pragma once
#include <stdlib.h>
#include "UiElement.h"
#include "UiBox.h"
#include "ofMain.h"

class UiRoot : public virtual UiBox {
public:
	static long hoveredElementId;
	static std::weak_ptr<UiElement> hoveredElement;
	static bool isLeftMouseDown;
	static bool isRightMouseDown;


	UiRoot() : UiBox(ElementOrientation::Vertical) {}

	static void calculateHoveredElement(std::shared_ptr<UiElement> element, float parentX, float parentY);

};