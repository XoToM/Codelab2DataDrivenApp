
#include <stdlib.h>
#include "ofApp.h"
#include "ofMain.h"
#include <screens/ScreenWelcome.h>


ofTrueTypeFont ofApp::titleFont;
ofTrueTypeFont ofApp::subTitleFont;
ofTrueTypeFont ofApp::normalFont;
shared_ptr<UiElement> ofApp::root;

//--------------------------------------------------------------
void ofApp::setup(){
	//	Load Fonts

	std::cout << "Font \"crunch chips\" 40px loaded? " << titleFont.load("fonts/crunch chips.otf", 40) << std::endl;	//	https://www.dafont.com/crunch-chips.font
	std::cout << "Font \"crunch chips\" 30px loaded? " << subTitleFont.load("fonts/crunch chips.otf", 30) << std::endl;	//	https://www.dafont.com/crunch-chips.font
	std::cout << "Font \"coolvetica rg\" 20px loaded? " << normalFont.load("fonts/coolvetica rg.otf", 20) << std::endl;	//	https://www.dafont.com/coolvetica.font

	root = make_shared<ScreenWelcome>();

}

//--------------------------------------------------------------
void ofApp::update(){
	root->onUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	root->onRender(0, 0);
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
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
