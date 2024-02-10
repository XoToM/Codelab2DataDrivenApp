
#include <stdlib.h>
#include "../UiElement.h"
#include "ofApp.h"
#include "../UiBox.h"
#include "../UiButton.h"
#include "../UiSpace.h"
#include "ofMain.h"
#include "../UiText.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//	Load Fonts


	titleFont.load("fonts/crunch chips.otf", 40);

	//	Initialize the User Interface

	root = make_shared<UiBox>(false); // 500,
	auto child1 = make_shared<UiButton>(); //150,
	child1->addChild(make_shared<UiText>("Left", &titleFont, 255, 255, 255, UiText::FontAlignment::Left));
	root->addChild(child1);

	root->addChild(make_shared<UiSpace>());

	auto child2 = make_shared<UiButton>(); //150,
	child2->setMargins(10);
	child2->addChild(make_shared<UiText>("Center", &titleFont, 255, 255, 255, UiText::FontAlignment::Center));
	root->addChild(child2);

	root->addChild(make_shared<UiSpace>());

	auto child3 = make_shared<UiButton>(); //150,
	child3->addChild(make_shared<UiText>("Right", &titleFont, 255, 255, 255, UiText::FontAlignment::Right));
	root->addChild(child3);
	root->addChild(make_shared<UiText>("Hello World!", &titleFont, 255,255,255));

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

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	root->onMousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	root->onMouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	//root->recalculateSize((float)w, (float)h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
