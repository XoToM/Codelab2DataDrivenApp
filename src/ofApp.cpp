
#include <stdlib.h>
#include "ofApp.h"
#include "../UiElement.h"
#include "../UiBox.h"
#include "ofMain.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//using namespace PokeApp::Ui;

	root = make_shared<UiBox>(0,0,500,500);
	auto child1 = make_shared<UiBox>(50, 50, 400, 300);
	root->addChild(child1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(ofColor::black);
	srand(155555555555);
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
