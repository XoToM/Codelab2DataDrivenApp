
#include <stdlib.h>
#include "ofApp.h"
#include "ofMain.h"
#include <screens/ScreenWelcome.h>


ofTrueTypeFont ofApp::titleFont;
ofTrueTypeFont ofApp::titleHighlightFont;
ofTrueTypeFont ofApp::subTitleFont;
ofTrueTypeFont ofApp::normalFont;
shared_ptr<UiElement> ofApp::root;
weak_ptr<UiElement> ofApp::hoveredElement;
ofApp* ofApp::mainApp;

//--------------------------------------------------------------
void ofApp::setup(){
	mainApp = this;
	//	Load Fonts


	subTitleFont.load("fonts/Retro Gaming.ttf", 35);	//	https://befonts.com/pokemon-font.html
	normalFont.load("fonts/Retro Gaming.ttf", 25);	//	https://www.dafont.com/retro-gaming.font

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
	if (button == 0) isLeftMousePressed = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) isLeftMousePressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == 0) isLeftMousePressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	this->isLeftMousePressed = false;
}


//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}


void ofApp::updateMouseHoveredElement(float mouseX, float mouseY, std::weak_ptr<UiElement> currentNode) {
	if (currentNode.expired()) return;

	hoveredElement = currentNode;
	auto fullPointer = hoveredElement.lock();
	for (auto child : fullPointer->Children) {
		if (child->isInBounds(mouseX-child->xPosition, mouseY - child->yPosition)) updateMouseHoveredElement(mouseX - child->xPosition, mouseY - child->yPosition, child);
	}
}