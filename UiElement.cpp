
#include "UiElement.h"
#include "uiSpaceAllocator.h"

void UiElement::recalculateSize() {
	calculateSizeOnXAxis(this->calculatedWidth, this->Children);
	for (auto& c : this->Children) {
		c->recalculateSize();
	}
}