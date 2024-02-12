#include "UiImage.h"
#include "ofApp.h"

UiImage::UiImage(std::string imageName, float x, float y, float width, float height) : UiElement(x,y, width, height){
	this->imageName = imageName;
}
void UiImage::onRender(float x, float y) {
	ofImage* image = &ofApp::mainApp->imageCache.at(this->imageName);
	if (!image->isAllocated()) return;
	ofSetColor(255, 255, 255);	//	Apparently openframeworks draws images with the color set here, so if this is all black, the entire image will also be black.
	image->draw(x, y, this->width, this->height);
}