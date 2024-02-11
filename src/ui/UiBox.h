#pragma once
#include "UiElement.h"
#include "ofMain.h"

class UiBox : public UiElement
{
public:
	ofColor fillColor;
	float borderRadius = 0;

	UiBox(float x, float y, float width, float height, ofColor fillColor = ofColor(0,0,0));
	void onRender(float x, float y);

	virtual ofColor getFillColor();
};

