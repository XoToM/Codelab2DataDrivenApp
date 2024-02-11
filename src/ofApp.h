#pragma once

#include "ofMain.h"
#include "ui/UiElement.h"

class ofApp : public ofBaseApp{

	public:
		static ofTrueTypeFont titleFont;
		static ofTrueTypeFont titleHighlightFont;
		static ofTrueTypeFont subTitleFont;
		static ofTrueTypeFont normalFont;

		static shared_ptr<UiElement> root;
		static ofApp* mainApp;

		static weak_ptr<UiElement> hoveredElement;

		bool isLeftMousePressed = false;

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
		void gotMessage(ofMessage msg);

		void updateMouseHoveredElement(float mouseX, float mouseY, std::weak_ptr<UiElement> currentNode);

		template <class T> static void changeScreens(std::shared_ptr<T> newScreen) {
			std::shared_ptr<UiElement> newScreenPointer = std::static_pointer_cast<UiElement, T>(newScreen);
			ofApp::root = newScreenPointer;
			ofApp::mainApp->updateMouseHoveredElement(ofGetMouseX(), ofGetMouseY(), newScreenPointer);
		}
};
