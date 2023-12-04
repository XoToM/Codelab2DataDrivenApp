#pragma once

#include "src/ofApp.h"
#include <vector>
#include <memory>
#include <type_traits>
#include <optional>
#include "boost/optional.hpp"

namespace poke_app {

	class PrefabBase {
	public:
		std::vector<std::shared_ptr<PrefabBase>> Children;
		boost::optional<std::weak_ptr<PrefabBase>> Parent = boost::none;

		ofApp* getApp();
		bool onMousePressed(int x, int y, int button);
		bool onMouseReleased(int x, int y, int button);
		bool onElementSelected();
		bool onElementDeselected();
		template<class T> void addChild(std::shared_ptr<T> new_child) {
			static_assert(std::is_base_of_v<PrefabBase, T>,"Class needs to extend PrefabBase");
			std::shared_ptr<PrefabBase> child = std::static_pointer_cast<PrefabBase, T>(new_child);

			//child->Parent = this;
		}
	};
};