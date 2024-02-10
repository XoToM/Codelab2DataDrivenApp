#pragma once
#include <stdlib.h>
#include "UiElement.h"

#include "boost/algorithm/string/classification.hpp"
#include "boost/algorithm/string/split.hpp"

//namespace PokeApp {
	//namespace Ui {
class UiText : public virtual UiElement {
private:
	vector<string> wordWrappedTextLines;
	string text;
	bool shouldRecalculateWordWrapping = true;
public:
	enum class FontAlignment { Left, Center, Right };

	ofTrueTypeFont* pFont;
	int Red;
	int Green;
	int Blue;
	FontAlignment textAlignment;


	UiText(string text, ofTrueTypeFont* pTextFont, int r=0, int g=0, int b=0, FontAlignment alignment=FontAlignment::Left) : UiElement() {
		this->text = text;
		this->pFont = pTextFont;
		Red = r;
		Green = g;
		Blue = b;
		textAlignment = alignment;
		performWordWrapping();
	}

	bool onRender(float parentX, float parentY) {
		float x = parentX + calculatedXPosition;
		float y = parentY + calculatedYPosition;
		float offset = 0;
		if (shouldRecalculateWordWrapping) {
			performWordWrapping();
			shouldRecalculateWordWrapping = false;
		}
		ofSetColor(this->Red, this->Green, this->Blue);

		for (string line : this->wordWrappedTextLines) {
			auto textBoundingBox = pFont->getStringBoundingBox(line, 0, 0);

			float textXPosition = x;
			float lineWidth = textBoundingBox.getWidth();
			switch (this->textAlignment) {
			case FontAlignment::Left:
				break;
			case FontAlignment::Right:
				textXPosition += this->calculatedWidth - lineWidth;
				break;
			case FontAlignment::Center:
				textXPosition += this->calculatedWidth / 2 - lineWidth / 2;
				break;
			}

			pFont->drawString(line, textXPosition, y + offset + textBoundingBox.getHeight());
			offset += pFont->getLineHeight();
		}
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

	virtual void recalculateSize(float containerWidth, float containerHeight) {
		UiElement::recalculateSize(containerWidth, containerHeight);

		shouldRecalculateWordWrapping = true;
	}
	void performWordWrapping() {
		wordWrappedTextLines.clear();
		std::vector<string> lines;
		boost::split(lines, this->text, boost::is_any_of("\n"));

		string wordWrappedLine;
		for (string line : lines) {
			std::vector<string> words;

			boost::split(words, line, boost::is_any_of(" "));
			for (string word : words) {
				string newWrappedLine = wordWrappedLine + word + ' ';
				float newLineWidth = pFont->stringWidth(newWrappedLine);
				if (newLineWidth > this->calculatedWidth) {
					if (wordWrappedLine.length() > 0 && wordWrappedLine[wordWrappedLine.length() - 1] == ' ') wordWrappedLine.pop_back();	//	Remove the last space of the string, since the extra space added by this algorithm could mess with how the text is centered.

					wordWrappedTextLines.push_back(wordWrappedLine);
					wordWrappedLine = word + ' ';
				}
				else {
					wordWrappedLine = newWrappedLine;
				}
			}
			if (wordWrappedLine.length() > 0 && wordWrappedLine[wordWrappedLine.length() - 1] == ' ') wordWrappedLine.pop_back();	//	Remove the last space of the string, since the extra space added by this algorithm could mess with how the text is centered.
			wordWrappedTextLines.push_back(wordWrappedLine);
		}
	}
	string getText() {
		return this->text;
	}

	void setText(string newText) {
		this->text = newText;
		shouldRecalculateWordWrapping = true;
	}
};
//}
//}
