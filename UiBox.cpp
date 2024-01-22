
#include "uiSpaceAllocator.h"
#include "UiBox.h"

void UiBox::recalculateSize(float containerWidth, float containerHeight) {
	if (this->isHorizontal) {
		calculateSizeOnXAxis(containerWidth, containerHeight, this->Children);
	}
	else {
		calculateSizeOnYAxis(containerWidth, containerHeight, this->Children);
	}
}