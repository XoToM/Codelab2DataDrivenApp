#pragma once
#include "../ui/UiBox.h"
#include <ofAppRunner.h>
class ScreenWelcome : public UiBox
{
public:
	ScreenWelcome() : UiBox(0, 0, ofGetWidth(), ofGetHeight()){
	}
};

