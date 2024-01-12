
#include "uiSpaceAllocator.h"
#include "UiBox.h"

void UiBox::recalculateSize(float containerSize) {
	calculateSizeOnXAxis(containerSize, this->Children);
}