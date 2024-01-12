
#include "UiElement.h"
#include "uiSpaceAllocator.h"

void UiElement::recalculateSize(float containerWidth, float containerHeight) {
	calculateSizeOnXAxis(containerWidth, containerHeight, this->Children);
}