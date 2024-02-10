#pragma once
#include "UiElement.h"

void calculateSizeOnXAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children);
void calculateSizeOnYAxis(float containerWidth, float containerHeight, std::vector<std::shared_ptr<UiElement>> children);