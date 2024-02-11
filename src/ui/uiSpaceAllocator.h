#pragma once
#include "UiElement.h"

void calculateSizeOnXAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children, UiElement::ElementAlignment mainAlignment, UiElement::ElementAlignment subAlignment);
void calculateSizeOnYAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children, UiElement::ElementAlignment mainAlignment, UiElement::ElementAlignment subAlignment);