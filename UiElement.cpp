
#include "UiElement.h"

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