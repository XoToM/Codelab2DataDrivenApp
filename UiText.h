#pragma once
#include <stdlib.h>
#include "UiElement.h"

//namespace PokeApp {
	//namespace Ui {
class UiText : public UiElement {
public:
	enum class FontAlignment { Left, Center, Right };

	string text;
	ofTrueTypeFont* pFont;
	int Red;
	int Green;
	int Blue;
	FontAlignment textAlignment;


	UiText(string text, ofTrueTypeFont* pTextFont, int r=0, int g=0, int b=0, FontAlignment alignment=FontAlignment::Left) {
		this->text = text;
		this->pFont = pTextFont;
		Red = r;
		Green = g;
		Blue = b;
		textAlignment = alignment;
	}

	bool onRender(float parentX, float parentY) {
		ofSetColor(this->Red, this->Green, this->Blue);
		auto textBoundingBox = pFont->getStringBoundingBox(this->text, 0,0);

		float textXPosition = parentX + calculatedXPosition;
		switch (this->textAlignment) {
			case FontAlignment::Left:
				break;
			case FontAlignment::Right:
				textXPosition += this->calculatedWidth - textBoundingBox.getWidth();
				break;
			case FontAlignment::Center:
				textXPosition += this->calculatedWidth/2 - textBoundingBox.getWidth()/2;
				break;
		}

		pFont->drawString(this->text, textXPosition, parentY + calculatedYPosition + textBoundingBox.getHeight());
		return true;
	}
	bool onClicked(int button) {
		return false;
	}
	bool onMousePressed(float x, float y, int button) {
		return false;
	}
	bool onMouseReleased(float x, float y, int button) {
		return false;
	}
	void recalculateSize(float containerWidth, float containerHeight) {}
};
//}
//}
