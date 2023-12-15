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
		public:
			std::vector<std::shared_ptr<UiElement>> Children;
			boost::optional<std::weak_ptr<UiElement>> Parent = boost::none;

			int relPosX;
			int relPosY;
			int width;
			int height;
			bool isPressed = false;
			bool isChildPressed = false;

			virtual bool onMousePressed(int x, int y, int button) {
				isChildPressed = true;
				for (auto child : this->Children) {
					int rx = x - child->relPosX;
					if (rx >= 0 && rx < child->width) {
						int ry = y - child->relPosY;
						if (ry >= 0 && ry < child->height) {
							if (child->onMousePressed(rx, ry, button)) return true;
						}
					}
				}
				isPressed = true;
				return true;
			}
			//virtual bool onMouseReleased(int x, int y, int button);

			virtual bool onMouseReleased(int x, int y, int button) {
				isChildPressed = false;
				isPressed = false;
				for (auto child : this->Children) {
					int rx = x - child->relPosX;
					if (rx >= 0 && rx < child->width) {
						int ry = y - child->relPosY;
						if (ry >= 0 && ry < child->height) {
							if (child->onMouseReleased(rx, ry, button)) return true;
						}
					}
				}

				return this->onClicked(button);
			}
			virtual bool onClicked(int button) = 0;
			//virtual bool onElementSelected();
			//virtual bool onElementDeselected();
			//virtual bool onKey();
			virtual bool onRender(int parentX, int parentY) = 0;

			template<class T> void addChild(std::shared_ptr<T> new_child) {	//	Templates have to be implemented in header files due to how c++ compilers work.
				static_assert(std::is_base_of_v<UiElement, T>, "Class needs to extend PrefabBase");
				std::shared_ptr<UiElement> child = std::static_pointer_cast<UiElement, T>(new_child);
				this->Children.push_back(child);
			}
		};
	//}
//};