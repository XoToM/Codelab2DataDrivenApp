
#include "uiSpaceAllocator.h"
#include "UiBox.h"

void UiBox::recalculateSize(float containerWidth, float containerHeight) {
	calculateSizeOnXAxis(containerWidth, containerHeight, this->Children);
}