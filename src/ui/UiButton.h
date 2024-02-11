#pragma once
#include "UiBox.h"
class UiButton : public UiBox
{
public:
	ofColor hoverColor = ofColor(245, 245, 245);
	ofColor clickColor = ofColor(230, 230, 230);

	UiButton(float x, float y, float width, float height);
	static std::shared_ptr<UiButton> makeButtonWithLabel(std::string text, float x, float y, float width=-1);

	ofColor getFillColor();
};

