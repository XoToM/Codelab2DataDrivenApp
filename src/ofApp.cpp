
#include <stdlib.h>
#include "ui/UiElement.h"
#include "ofApp.h"
#include "ui/UiBox.h"
#include "ui/UiRoot.h"
#include "ui/UiButton.h"
#include "ui/UiSpace.h"
#include "ofMain.h"
#include "ui/UiText.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//	Load Fonts


	titleFont.load("fonts/crunch chips.otf", 40);	//	https://www.dafont.com/crunch-chips.font

	//	Initialize the User Interface

	root = make_shared<UiRoot>();	//	Create the root element and initialize it.
	UiRoot::calculateHoveredElement(root,-1,-1);

	auto child1 = make_shared<UiButton>(); //150,
	child1->addChild(make_shared<UiText>("Left", &titleFont, 255, 255, 255, UiText::FontAlignment::Left));
	root->addChild(child1);

	root->addChild(make_shared<UiSpace>());

	auto child2 = make_shared<UiButton>(); //150,
	child2->setMargins(10,10,10,100);
	child2->addChild(make_shared<UiText>("This is a piece of a very very long text which should be centered, but it should also wrap around the edge of this element.", &titleFont, 255, 255, 255, UiText::FontAlignment::Center));
	root->addChild(child2);

	root->addChild(make_shared<UiSpace>());

	auto child3 = make_shared<UiButton>(); //150,
	child3->addChild(make_shared<UiText>("Right", &titleFont, 255, 255, 255, UiText::FontAlignment::Right));
	root->addChild(child3);
	root->addChild(make_shared<UiText>("Hello, World!", &titleFont, 255,255,255));

	child2->growFactor = 5;
	child3->growFactor = 0;
	child3->minWidth = 100;
	child3->minHeight = 100;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	auto windowSize = ofGetWindowSize();
	if (lastKnownWidth != ofGetWidth() || lastKnownHeight != ofGetHeight()) {
		lastKnownWidth = ofGetWidth();
		lastKnownHeight = ofGetHeight();
	}
	root->recalculateSize(lastKnownWidth, lastKnownHeight);
	ofClear(ofColor::black);
	srand(155555555554);
	root->onRender(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	UiRoot::calculateHoveredElement(root, (float)x, (float)y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	UiRoot::calculateHoveredElement(root, (float)x, (float)y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	UiRoot::calculateHoveredElement(root, (float)x, (float)y);
	switch (button) {
	case 0:
		UiRoot::isLeftMouseDown = true;
		break;
	case 2:
		UiRoot::isRightMouseDown = true;
		break;
	}
	UiRoot::isLeftMouseDown = true;
	root->onMousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	UiRoot::calculateHoveredElement(root, (float)x, (float)y);
	switch (button) {
		case 0:
			UiRoot::isLeftMouseDown = false;
			break;
		case 2:
			UiRoot::isRightMouseDown = false;
			break;
	}
	root->onMouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	UiRoot::calculateHoveredElement(root, (float)x, (float)y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	UiRoot::calculateHoveredElement(root, -1, -1);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	UiRoot::calculateHoveredElement(root, (float)ofGetMouseX(), (float)ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
