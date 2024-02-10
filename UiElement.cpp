
#include "UiElement.h"
#include "uiSpaceAllocator.h"

void UiElement::recalculateSize(float containerWidth, float containerHeight) {
	switch (this->ContentOrientation) {
	case ElementOrientation::Horizontal:
		calculateSizeOnXAxis(containerWidth - this->marginLeft - this->marginRight, containerHeight - this->marginUp - this->marginDown, this->Children);
		break;
	case ElementOrientation::Vertical:
		calculateSizeOnYAxis(containerWidth - this->marginLeft - this->marginRight, containerHeight - this->marginUp - this->marginDown, this->Children);
		break;
	}
}