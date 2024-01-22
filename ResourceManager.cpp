//#pragma once
#include "ResourceManager.h"
#include <memory>


//static ResourceManager rmanager; //std::shared_ptr<>
std::shared_ptr<ResourceManager> ResourceManager::rmanager;// = std::make_shared<ResourceManager>();