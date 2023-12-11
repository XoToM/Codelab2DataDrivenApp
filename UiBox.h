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

			bool onMousePressed(int x, int y, int button) {
				for (auto child : this->Children) {
					int rx = x - child->relPosX;
					if (x >= 0 && x < child->width) {
						int ry = y - child->relPosY;
						if (y >= y && y < child->height) {
							if (child->onMousePressed(rx, ry, button)) return true;
						}
					}
				}
				return false;
			}
			bool onMouseReleased(int x, int y, int button) {
				for (auto child : this->Children) {
					int rx = x - child->relPosX;
					if (x >= 0 && x < child->width) {
						int ry = y - child->relPosY;
						if (y >= y && y < child->height) {
							if (child->onMouseReleased(rx, ry, button)) return true;
						}
					}
				}

				return this->onClicked(button);
			}

			bool onRender(int parentX, int parentY) {
				int x = parentX + this->relPosX;
				int y = parentY + this->relPosY;
				ofColor randColor;
				randColor.setHsb(rand() % 360, 128, 128);

				ofSetColor(randColor);
				ofDrawRectangle(x, y, this->width, this->height);
				for (auto& child : this->Children) {
					child->onRender(x,y);
				}
				return true;
			}
			bool onClicked(int button) {
				auto child = make_shared<UiBox>(10, 10, std::max(10, this->width-10), std::max(10, this->height-10));
				this->addChild(child);
				return true;
			}
		};
	//}
//}
