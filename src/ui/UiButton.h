#pragma once
#include "UiBox.h"
class UiButton : public UiBox
{
public:
	UiButton(float x, float y, float width, float height);
	static std::shared_ptr<UiButton> makeButtonWithLabel(std::string text, float x, float y, float width, float height);
};

