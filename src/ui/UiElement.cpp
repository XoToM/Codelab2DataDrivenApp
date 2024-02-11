#include "UiElement.h"

long UiElement::uniqueIdCounter = 0;

bool UiElement::isInBounds(float relX, float relY) {	//	Take coorditanes of a point relative to the top left corner of this element, and determine if the given point is inside this element or not
	return relX >= 0 && relY >= 0 && relX < this->width && relY < this->height;
}
void UiElement::onRender(float x, float y) {
	for (auto child : this->Children) {	//	Call onRender on all the child elements
		child->onRender(x + child->xPosition, y + child->yPosition);
	}
}
void UiElement::onUpdate() {
	for (auto child : this->Children) {	//	Call onUpdate on all the child elements
		child->onUpdate();
	}
}

UiElement::UiElement(float x, float y, float width, float height) {
	this->width = width;	//	Save the arguments of this constructor as fields of this class.
	this->height = height;
	this->xPosition = x;
	this->yPosition = y;

	this->uniqueId = uniqueIdCounter++;	//	Generates a unique id for this element. I have done the maths, and even if this program created 1000 elements per second (1 every millisecond), the computer running this program will decompose before this counter overflows (time for e-waste to decompose is somewhere between 50 years and 1 million years, and this will take aproximately 584 million years to overflow). This means that we can safely assume this id is going to be unique.
}