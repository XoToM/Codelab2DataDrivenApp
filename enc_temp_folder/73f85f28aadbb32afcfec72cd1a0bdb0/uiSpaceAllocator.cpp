#include "UiElement.h"

void calculateSizeOnXAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children) {
	auto minimumWidth = 0;
	for (auto& c : children) {
		minimumWidth += c->minWidth;
		c->sizeCalculationDoneEarly = false;
	}
	int growPoints;
	float spaceLeft = containerWidth - minimumWidth;
	float spacePerPoint = 0;
	while (true) {
		growPoints = 0;
		for (auto& c : children) {
			if (c->sizeCalculationDoneEarly) continue;
			growPoints += c->growFactor;
		}
		if (growPoints == 0) break;
		spacePerPoint = spaceLeft / growPoints;
		bool corrected = false;
		for (auto& c : children) {
			if (c->sizeCalculationDoneEarly || c->maxWidth < 0) continue;
			if (c->growFactor * spacePerPoint > (c->maxWidth - c->minWidth)) {
				corrected = true;
				spaceLeft -= (c->maxWidth - c->minWidth);
				float newWidth = c->maxWidth;
				c->sizeCalculationDoneEarly = true;


				float newHeight = std::max(c->minHeight, containerHeight);
				if (c->maxHeight >= 0) c->calculatedBoxHeight = std::min(c->maxHeight, c->calculatedBoxHeight);

				if (c->calculatedBoxHeight != newHeight || c->calculatedBoxWidth != newWidth) {
					c->calculatedBoxWidth = newWidth;
					c->calculatedBoxHeight = newHeight;
					c->recalculateSize(newWidth, c->calculatedBoxHeight);
				}
			}
		}
		if (!corrected) {
			break;
		}
	}
	for (auto& c : children) {
		if (c->sizeCalculationDoneEarly) continue;
		float newWidth = c->growFactor * spacePerPoint + c->minWidth;

		float newHeight = std::max(c->minHeight, containerHeight);
		if (c->maxHeight >= 0) c->calculatedBoxHeight = std::min(c->maxHeight, c->calculatedBoxHeight);

		if (c->calculatedBoxHeight != newHeight || c->calculatedBoxWidth != newWidth) {
			c->calculatedBoxWidth = newWidth;
			c->calculatedBoxHeight = newHeight;
			c->recalculateSize(c->calculatedBoxWidth, c->calculatedBoxHeight);
		}
		
		c->sizeCalculationDoneEarly = true;
	}
	float offset = 0;
	for (auto& c : children) {
		c->calculatedWidth = c->calculatedBoxWidth - c->marginLeft - c->marginRight;
		c->calculatedHeight = c->calculatedBoxHeight - c->marginUp - c->marginDown;

		c->calculatedXPosition = offset + c->marginLeft;
		c->calculatedYPosition = c->marginUp;
		offset += c->calculatedBoxWidth;
	}
}

void calculateSizeOnYAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children) {
	auto minimumHeight = 0;
	for (auto& c : children) {
		minimumHeight += c->minHeight;
		c->sizeCalculationDoneEarly = false;
	}
	int growPoints;
	float spaceLeft = containerHeight - minimumHeight;
	float spacePerPoint = 0;
	while (true) {
		growPoints = 0;
		for (auto& c : children) {
			if (c->sizeCalculationDoneEarly) continue;
			growPoints += c->growFactor;
		}
		if (growPoints == 0) break;
		spacePerPoint = spaceLeft / growPoints;
		bool corrected = false;
		for (auto& c : children) {
			if (c->sizeCalculationDoneEarly || c->maxHeight < 0) continue;
			if (c->growFactor * spacePerPoint > (c->maxHeight - c->minHeight)) {
				corrected = true;
				spaceLeft -= (c->maxHeight - c->minHeight);
				float newHeight = c->maxHeight;
				c->sizeCalculationDoneEarly = true;

				float newWidth = std::max(c->minWidth, containerWidth);
				if (c->maxWidth >= 0) c->calculatedBoxWidth = std::min(c->maxWidth, c->calculatedBoxWidth);

				if (c->calculatedBoxHeight != newHeight || c->calculatedBoxWidth != newWidth) {
					c->calculatedBoxWidth = newWidth;
					c->calculatedBoxHeight = newHeight;
					c->recalculateSize(c->calculatedBoxWidth, c->calculatedBoxHeight);
				}
			}
		}
		if (!corrected) {
			break;
		}
	}
	for (auto& c : children) {
		if (c->sizeCalculationDoneEarly) continue;
		float newHeight = c->growFactor * spacePerPoint + c->minHeight;
		float newWidth = std::max(c->minWidth, containerWidth);
		if (c->maxWidth >= 0) c->calculatedBoxWidth = std::min(c->maxWidth, c->calculatedBoxWidth);

		if (c->calculatedBoxHeight != newHeight || c->calculatedBoxWidth != newWidth) {
			c->calculatedBoxWidth = newWidth;
			c->calculatedBoxHeight = newHeight;
			c->recalculateSize(c->calculatedBoxWidth, c->calculatedBoxHeight);
		}
		c->sizeCalculationDoneEarly = true;
	}
	float offset = 0;
	for (auto& c : children) {
		c->calculatedWidth = c->calculatedBoxWidth - c->marginLeft - c->marginRight;
		c->calculatedHeight = c->calculatedBoxHeight - c->marginUp - c->marginDown;

		c->calculatedXPosition = c->marginLeft;
		c->calculatedYPosition = offset + c->marginUp;
		offset += c->calculatedBoxHeight;
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