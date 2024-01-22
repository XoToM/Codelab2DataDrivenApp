#pragma once

#include <stdlib.h>
#include <memory>
#include <ofMain.h>



class ResourceManager {
public:
	ofTrueTypeFont defaultFont;
	static std::shared_ptr<ResourceManager> rmanager; //std::shared_ptr<>

	static void InitResourceManager() {
		rmanager = std::make_shared<ResourceManager>();
		std::cout << "Resource Manager Ready" << std::endl;
	}
	ResourceManager() {
		ResourceManager::defaultFont.load("file.ttf", 20);
	}

	static ofTrueTypeFont getDefaultFont() {
		return rmanager->defaultFont;
	}

};
