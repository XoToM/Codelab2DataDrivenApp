#pragma once
/*
#include "UiElement.h"
#include <stdlib.h>
#include "ofMain.h"

namespace PokeApp {
	namespace Ui {
		class UiButton : public UiElement {
		public:
			UiButton(int relX, int relY, int width, int height) {
				this->relPosX = relX;
				this->relPosY = relY;
				this->width = width;
				this->height = height;
			}

			bool onMousePressed(int x, int y, int button) { return false; }
			bool onMouseReleased(int x, int y, int button) { return false; }
			bool onElementSelected() { return false; }
			bool onElementDeselected() { return false; }
			bool onKey() { return false; }

			bool onRender(int parentX, int parentY) {
				int x = parentX + this->relPosX;
				int y = parentY + this->relPosY;
				ofColor randColor;
				randColor.setHsb(rand() % 360, 128, 128);

				ofSetColor(randColor);
				ofDrawRectangle(x, y, this->width, this->height);
				for (auto child : this->Children) {
					child->onRender(x, y);
				}
				return true;
			}
		};
	}
}//*/
