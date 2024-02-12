
#include <stdlib.h>
#include "ofApp.h"
#include "ofMain.h"
#include <screens/ScreenWelcome.h>
#include <screens/ScreenError.h>


ofTrueTypeFont ofApp::titleFont;
ofTrueTypeFont ofApp::titleHighlightFont;
ofTrueTypeFont ofApp::subTitleFont;
ofTrueTypeFont ofApp::normalFont;
ofTrueTypeFont ofApp::smallFont;
shared_ptr<UiElement> ofApp::root;
weak_ptr<UiElement> ofApp::hoveredElement;
ofApp* ofApp::mainApp;

//--------------------------------------------------------------
void ofApp::setup(){
	//	Set up static variables
	mainApp = this;

	//	Load Fonts


	titleFont.load("fonts/Pokemon Solid.ttf", 50);	//	https://befonts.com/pokemon-font.html
	titleHighlightFont.load("fonts/Pokemon Hollow.ttf", 50);	//	https://befonts.com/pokemon-font.html

	subTitleFont.load("fonts/Retro Gaming.ttf", 35);	//	https://www.dafont.com/retro-gaming.font
	normalFont.load("fonts/Retro Gaming.ttf", 25);	//	https://www.dafont.com/retro-gaming.font
	smallFont.load("fonts/Retro Gaming.ttf", 20);	//	https://www.dafont.com/retro-gaming.font

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
	ofApp::showError();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (button == 0) isLeftMousePressed = true;
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) isLeftMousePressed = true;
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
	if (button == 0) {
		isLeftMousePressed = false;
		ofApp::root->onClick((float)x, (float)y);
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	ofApp::updateMouseHoveredElement(x, y, ofApp::root);
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

void ofApp::showError() {
	ofApp::changeScreens(make_shared<ScreenError>());
}
