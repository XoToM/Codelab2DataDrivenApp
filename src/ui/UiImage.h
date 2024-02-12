#pragma once
#include "UiElement.h"
#include <string>

class UiImage : public UiElement
{
public:
	bool blindImage = false;
	std::string imageName;
	UiImage(std::string imageName, float x, float y, float width, float height);

	void onRender(float x, float y);
};

