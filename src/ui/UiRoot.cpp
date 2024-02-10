
#include "UiRoot.h"

long UiRoot::hoveredElementId = 0;
std::weak_ptr<UiElement> UiRoot::hoveredElement;
bool UiRoot::isLeftMouseDown = false;
bool UiRoot::isRightMouseDown = false;

void UiRoot::calculateHoveredElement(std::shared_ptr<UiElement> element, float parentX, float parentY) {

	 hoveredElementId = element->uniqueIdentifier;	//	If this function got executed, then that means either the current element is being hovered over, or we are testing the root elemet. The root element is used to represent the mouse not hovering over any element, so if none of its children are hovered over, then the user is not hovering over anything.
	 hoveredElement = element;

	 for (auto child : element->Children) {
		 float relX = parentX - child->calculatedXPosition;
		 float relY = parentY - child->calculatedYPosition;

		 if (relX >= 0 && relY >= 0 && relX < child->calculatedWidth && relY < child->calculatedHeight) {
			 calculateHoveredElement(child, relX, relY);
			 return;
		 }
	 }
}