#pragma once
#include "UiElement.h"
#include "ofMain.h"

class UiBox : public UiElement
{
public:
	ofColor fillColor = ofColor(0, 0, 0);
	float borderRadius = 0;

	UiBox(float x, float y, float width, float height);
	void onRender(float x, float y);

	virtual ofColor getFillColor();
};

