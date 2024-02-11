#pragma once

#include "ofMain.h"
#include "ui/UiElement.h"

class ofApp : public ofBaseApp{

	public:
		static ofTrueTypeFont titleFont;
		static ofTrueTypeFont subTitleFont;
		static ofTrueTypeFont normalFont;

		static shared_ptr<UiElement> currentScreen;

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
