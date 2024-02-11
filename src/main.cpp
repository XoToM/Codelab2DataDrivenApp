#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	//ofRunApp(new ofApp());

	ofGLFWWindowSettings settings;
	settings.resizable = false;
	settings.setSize(1024, 768);
	ofCreateWindow(settings);
	return ofRunApp(new ofApp);
}
