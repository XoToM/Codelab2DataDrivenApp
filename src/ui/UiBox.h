#pragma once
#include <stdlib.h>
#include "UiElement.h"
#include "ofMain.h"

//namespace PokeApp {
	//namespace Ui {
		class UiBox : public virtual UiElement {
		public:
			boost::optional<ofColor> defaultColor;
			boost::optional<ofColor> hoverColor;
			boost::optional<ofColor> activeColor;

			UiBox(UiElement::ElementOrientation orientation = UiElement::ElementOrientation::Horizontal) : UiElement() {
				this->ContentOrientation = orientation;
			}

			bool onRender(float parentX, float parentY) {
				float x = parentX + this->calculatedXPosition;
				float y = parentY + this->calculatedYPosition;

				bool render = false;

				if (defaultColor) {
					ofSetColor(defaultColor.get());
					render = true;
				}
				if (hoverColor && isHoveredOver()) {
					ofSetColor(hoverColor.get());
					render = true;
				}
				if (activeColor && isActive()) {
					ofSetColor(activeColor.get());
					render = true;
				}
				

				if (render) {
					ofDrawRectangle(x, y, this->calculatedWidth, this->calculatedHeight);
				}
				for (auto& child : this->Children) {
					child->onRender(x,y);
				}
				return true;
			}

			virtual bool isActive() {
				return false;
			}
		};
	//}
//}
