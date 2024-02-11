
#include "UiElement.h"
#include "UiRoot.h"
#include "uiSpaceAllocator.h"

long UiElement::uniqueIdentifierCounter = 0;

void UiElement::recalculateSize(float containerWidth, float containerHeight) {
	switch (this->ContentOrientation) {
	case ElementOrientation::Horizontal:
		calculateSizeOnXAxis(containerWidth - this->marginLeft - this->marginRight, containerHeight - this->marginUp - this->marginDown, this->Children, this->MainContentAlignment, this->SubContentAlignment);
		break;
	case ElementOrientation::Vertical:
		calculateSizeOnYAxis(containerWidth - this->marginLeft - this->marginRight, containerHeight - this->marginUp - this->marginDown, this->Children, this->MainContentAlignment, this->SubContentAlignment);
		break;
	}
}
bool UiElement::isHoveredOver() {
	if (UiRoot::hoveredElementId == this->uniqueIdentifier) return true;
	for (auto child : this->Children) {
		if (child->isHoveredOver()) return true;
	}
	return false;
}