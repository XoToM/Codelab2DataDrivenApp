#include "UiElement.h"

void calculateSizeOnXAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children) {
	auto minimumWidth = 0;
	for (auto& c : children) {
		minimumWidth += c->requestedMinWidth;
		c->sizeCalculationTemporaryMarker = false;
		c->calculatedHeight = std::max(c->requestedMinHeight, containerHeight);
		if(c->requestedMaxHeight >= 0) c->calculatedHeight = std::min(c->requestedMaxHeight, c->calculatedHeight);
		//c->calculatedWidth = c->requestedMinWidth;
	}
	int growPoints;
	float spaceLeft = containerWidth - minimumWidth;
	float spacePerPoint = 0;
	while (true) {
		growPoints = 0;
		for (auto& c : children) {
			if (c->sizeCalculationTemporaryMarker) continue;
			growPoints += c->growPoints;
		}
		if (growPoints == 0) break;
		spacePerPoint = spaceLeft / growPoints;
		bool corrected = false;
		for (auto& c : children) {
			if (c->sizeCalculationTemporaryMarker || c->requestedMaxWidth < 0) continue;
			if (c->growPoints * spacePerPoint > (c->requestedMaxWidth - c->requestedMinWidth)) {
				corrected = true;
				spaceLeft -= (c->requestedMaxWidth - c->requestedMinWidth);
				float newWidth = c->requestedMaxWidth;
				c->sizeCalculationTemporaryMarker = true;
				if (c->calculatedWidth != newWidth) {
					c->calculatedWidth = newWidth;
					c->recalculateSize(newWidth, c->calculatedHeight);
				}
			}
		}
		if (!corrected) {
			break;
		}
	}
	for (auto& c : children) {
		if (c->sizeCalculationTemporaryMarker) continue;
		float newWidth = c->growPoints * spacePerPoint + c->requestedMinWidth;
		if (c->calculatedWidth != newWidth) {
			c->calculatedWidth = newWidth;
			c->recalculateSize(newWidth, c->calculatedHeight);
		}
		c->sizeCalculationTemporaryMarker = true;
	}
	float offset = 0;
	for (auto& c : children) {
		c->calculatedXPosition = offset;
		offset += c->calculatedWidth;
	}
}

void calculateSizeOnYAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children) {
	auto minimumHeight = 0;
	for (auto& c : children) {
		minimumHeight += c->requestedMinHeight;
		c->sizeCalculationTemporaryMarker = false;
		//c->calculatedWidth = c->requestedMinWidth;
		c->calculatedWidth = std::max(c->requestedMinWidth, containerWidth);
		if (c->requestedMaxWidth >= 0) c->calculatedWidth = std::min(c->requestedMaxWidth, c->calculatedWidth);
	}
	int growPoints;
	float spaceLeft = containerHeight - minimumHeight;
	float spacePerPoint = 0;
	while (true) {
		growPoints = 0;
		for (auto& c : children) {
			if (c->sizeCalculationTemporaryMarker) continue;
			growPoints += c->growPoints;
		}
		if (growPoints == 0) break;
		spacePerPoint = spaceLeft / growPoints;
		bool corrected = false;
		for (auto& c : children) {
			if (c->sizeCalculationTemporaryMarker || c->requestedMaxHeight < 0) continue;
			if (c->growPoints * spacePerPoint > (c->requestedMaxHeight - c->requestedMinHeight)) {
				corrected = true;
				spaceLeft -= (c->requestedMaxHeight - c->requestedMinHeight);
				float newHeight = c->requestedMaxHeight;
				c->sizeCalculationTemporaryMarker = true;
				if (c->calculatedHeight != newHeight) {
					c->calculatedHeight = newHeight;
					c->recalculateSize(c->calculatedWidth, newHeight);
				}
			}
		}
		if (!corrected) {
			break;
		}
	}
	for (auto& c : children) {
		if (c->sizeCalculationTemporaryMarker) continue;
		float newHeight = c->growPoints * spacePerPoint + c->requestedMinHeight;
		if (c->calculatedHeight != newHeight) {
			c->calculatedHeight = newHeight;
			c->recalculateSize(c->calculatedWidth, newHeight);
		}
		c->sizeCalculationTemporaryMarker = true;
	}
	float offset = 0;
	for (auto& c : children) {
		c->calculatedYPosition = offset;
		offset += c->calculatedHeight;
	}
}
 /*
	 Layout calculations:
		 Ignore the sizes of the children, only calculate size based on the parent element and fixed values. Once size is calculated perform this algorithm on the child elements.
		 To control positions of elements invisible padding elements can be used.
		 This will work fine for elements with a fixed (and known at compile time) number of children, for elements with a variable number of children special scrollable elements can be used.

	 SizeValues = Fixed size, Fixed size based on container size
		 - Dependencies = Container size, Size of sibling elements
	 GrowProperties = Priority and Ratio


		 Steps:
			 1. Calculate Fixed sizes of children (Minimum and maximum sizes)
				 -	Arguments = Container size, (fixed sizes)
				 - Return fixed sizes
				 - Calculate Percentage based sizes
				 - Return
			 2. Calculate remaining space
				 - Take minimum sizes
				 - Subtract from total space available
			 3. Calculate growing elements
				 -	While there is an element with an unreached maximum size
					 -	Take elements with highest growing priority
					 -	Split remaining space between them
					 - For every one of these elements which reached its maximum size
						 - Mark element as completed
						 - Calculate unused allocated space
						 - Mark this unused space as unused
			 4. Perform this algorithm on all child elements
 */