#pragma once
#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"

//namespace PokeApp {
	//namespace Ui {
		class UiBox : public UiElement {
		public:
			UiBox(int relX, int relY, int width, int height) {
				this->relPosX = relX;
				this->relPosY = relY;
				this->width = width;
				this->height = height;
			}

			bool onRender(int parentX, int parentY) {
				int x = parentX + this->relPosX;
				int y = parentY + this->relPosY;
				ofColor randColor;
				randColor.setHsb(rand() % 360, 128, 128);
				ofColor altRandColor;
				altRandColor.setHsb(rand() % 360, 128, 128);

				ofSetColor(randColor);
				if(isPressed) ofSetColor(altRandColor);

				ofDrawRectangle(x, y, this->width, this->height);
				for (auto& child : this->Children) {
					child->onRender(x,y);
				}
				return true;
			}
			bool onClicked(int button) {
				return true;
			}
			void recalculateSize();
		};
	//}
//}
