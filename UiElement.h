#pragma once

#include <vector>
#include <memory>
#include <type_traits>
#include <optional>
//#include "src/ofApp.h"
#include "boost/optional.hpp"
#include "ofMain.h"

//namespace PokeApp {
	//namespace Ui {

		class UiElement {
		private:
			static long uniqueIdentifierCounter;
		public:
			enum class ElementOrientation { Horizontal, Vertical };

			long uniqueIdentifier;	//	Used to make finding and comparing elements easier.

			std::vector<std::shared_ptr<UiElement>> Children;
			boost::optional<std::weak_ptr<UiElement>> Parent = boost::none;


			float calculatedXPosition = 0;	//	The calculated position of this element relative to its parent
			float calculatedYPosition = 0;

			float calculatedBoxWidth = 0;	//	The total width and height allocated to this element (Including padding)
			float calculatedBoxHeight = 0;

			float calculatedWidth = 0;	//	The width and height of this element (Excluding padding)
			float calculatedHeight = 0;

			float minWidth = 0;		//	The minimum and maximum size of this element
			float minHeight = 0;
			float maxWidth = -1;
			float maxHeight = -1;

			int growFactor = 1;	//	How quickly this element should grow along the main axis of its parent when given the chance

			bool sizeCalculationDoneEarly = false;	//	Only used by the space allocation algorithm to mark when the space for this element got allocated. 

			float marginLeft = 0;
			float marginRight = 0;
			float marginUp = 0;
			float marginDown = 0;

			ElementOrientation ContentOrientation = ElementOrientation::Horizontal;

			UiElement() {
				this->uniqueIdentifier = UiElement::uniqueIdentifierCounter++;	//	Allocate a unique id to this element. Pretty much guaranteed to be unique since the computer running this program would probably decompose before this counter overflowed.
			}

			void setMargins(float up=-1, float right=-1, float down=-1, float left=-1) {

				if (up < 0) up = 0;
				if (right < 0) right = up;
				if (down < 0) down = up;
				if (left < 0) left = right;

				this->marginUp = up;
				this->marginRight = right;
				this->marginDown = down;
				this->marginLeft = left;
			}

			virtual bool onMousePressed(float x, float y, int button) {
				for (auto child : this->Children) {
					int rx = x - child->calculatedXPosition;
					if (rx >= 0 && rx < child->calculatedBoxWidth) {
						int ry = y - child->calculatedYPosition;
						if (ry >= 0 && ry < child->calculatedBoxHeight) {
							if (child->onMousePressed(rx, ry, button)) return true;
						}
					}
				}
				return true;
			}

			virtual bool onMouseReleased(float x, float y, int button) {
				for (auto child : this->Children) {
					int rx = x - child->calculatedXPosition;
					if (rx >= 0 && rx < child->calculatedBoxWidth) {
						int ry = y - child->calculatedYPosition;
						if (ry >= 0 && ry < child->calculatedBoxHeight) {
							if (child->onMouseReleased(rx, ry, button)) return true;
						}
					}
				}

				return this->onClicked(button);
			}
			virtual bool onClicked(int button) { 
				return false;
			}

			virtual bool onRender(float parentX, float parentY) = 0;

			template<class T> void addChild(std::shared_ptr<T> new_child) {	//	Templates have to be implemented in header files due to how c++ compilers work.
				static_assert(std::is_base_of_v<UiElement, T>, "Class needs to extend PrefabBase");
				std::shared_ptr<UiElement> child = std::static_pointer_cast<UiElement, T>(new_child);
				this->Children.push_back(child);
			}

			virtual void recalculateSize(float containerWidth, float containerHeight);

			bool isHoveredOver();

		};
	//}
//};