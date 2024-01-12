
#include "UiElement.h"
#include "uiSpaceAllocator.h"

void UiElement::recalculateSize(float containerSize) {
	calculateSizeOnXAxis(containerSize, this->Children);
}