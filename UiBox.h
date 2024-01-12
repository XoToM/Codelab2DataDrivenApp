#pragma once
#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"

//namespace PokeApp {
	//namespace Ui {
		class UiBox : public UiElement {
		public:
			UiBox(int relX, int relY, int height) {// int width,
				this->relPosX = relX;
				this->relPosY = relY;
				//this->width = width;
				this->height = height;
			}

			bool onRender(float parentX, float parentY) {
				float x = parentX + this->calculatedXPosition;
				float y = parentY + this->relPosY;
				ofColor randColor;
				randColor.setHsb(rand() % 360, 128, 128);
				ofColor altRandColor;
				altRandColor.setHsb(rand() % 360, 128, 128);

				ofSetColor(randColor);
				if(isPressed) ofSetColor(altRandColor);

				ofDrawRectangle(x, y, this->calculatedWidth, (float)this->height);
				for (auto& child : this->Children) {
					child->onRender(x,y);
				}
				return true;
			}
			bool onClicked(int button) {
				return true;
			}
			void recalculateSize(float containerSize);
		};
	//}
//}
