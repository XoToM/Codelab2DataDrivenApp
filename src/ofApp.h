#pragma once

#include "ofMain.h"
#include "../UiRoot.h"

class ofApp : public ofBaseApp{

	public:
		ofTrueTypeFont titleFont;
		std::shared_ptr<UiRoot> root;
		int lastKnownWidth = 0;
		int lastKnownHeight = 0;

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
