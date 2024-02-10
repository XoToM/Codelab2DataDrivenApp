
#include "UiElement.h"
#include "uiSpaceAllocator.h"

void UiElement::recalculateSize(float containerWidth, float containerHeight) {
	switch (this->ContentOrientation) {
	case ElementOrientation::Horizontal:
		calculateSizeOnXAxis(containerWidth, containerHeight, this->Children);
		break;
	case ElementOrientation::Vertical:
		calculateSizeOnYAxis(containerWidth, containerHeight, this->Children);
		break;
	}
}