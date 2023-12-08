#pragma once

#include "src/ofApp.h"
#include <vector>
#include <memory>
#include <type_traits>
#include <optional>
#include "boost/optional.hpp"
#include "ofMain.h"

namespace PokeApp {
	namespace Ui {

		class UiElement {
		public:
			std::vector<std::shared_ptr<UiElement>> Children;
			boost::optional<std::weak_ptr<UiElement>> Parent = boost::none;

			int relPosX;
			int relPosY;
			int width;
			int height;

			//virtual bool onMousePressed(int x, int y, int button);
			//virtual bool onMouseReleased(int x, int y, int button);
			//virtual bool onElementSelected();
			//virtual bool onElementDeselected();
			//virtual bool onKey();
			virtual bool onRender(int parentX, int parentY) = 0;

			template<class T> void addChild(std::shared_ptr<T> new_child) {
				static_assert(std::is_base_of_v<UiElement, T>, "Class needs to extend PrefabBase");
				std::shared_ptr<UiElement> child = std::static_pointer_cast<UiElement, T>(new_child);
				this->Children.push_back(child);
			}
		};
	}
};