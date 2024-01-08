
#include "uiSpaceAllocator.h"
#include "UiBox.h"

void UiBox::recalculateSize() {
	calculateSizeOnXAxis(this->calculatedWidth, this->Children);
	for (auto& c : this->Children) {
		c->recalculateSize();
	}
}