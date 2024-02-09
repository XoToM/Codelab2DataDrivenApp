
#include <stdlib.h>
#include "../UiElement.h"
#include "ofApp.h"
#include "../UiBox.h"
#include "../UiButton.h"
#include "../UiSpace.h"
#include "../UiPadding.h"
#include "ofMain.h"
#include "../ResourceManager.h"
#include "../UiText.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//using namespace PokeApp::Ui;

	root = make_shared<UiBox>(false); // 500,
	auto child1 = make_shared<UiButton>(); //150,
	root->addChild(child1);

	root->addChild(make_shared<UiSpace>());

	auto child2 = make_shared<UiPadding<UiButton>>(make_shared<UiButton>(),10); //150,
	root->addChild(child2);

	root->addChild(make_shared<UiSpace>());

	auto child3 = make_shared<UiButton>(); //150,
	root->addChild(child3);
	root->addChild(make_shared<UiText>("Hello World!"));

	child2->growPoints = 5;
	child3->growPoints = 0;
	child3->requestedMinWidth = 100;
	child3->requestedMinHeight = 100;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	auto window_size = ofGetWindowSize();
	if (lastKnownWidth != window_size.x || lastKnownHeight != window_size.y) {
		lastKnownWidth = window_size.x;
		lastKnownHeight = window_size.y;
		root->recalculateSize(lastKnownWidth, lastKnownHeight);
	}
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
