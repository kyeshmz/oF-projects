#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDelaunay.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    ofVideoGrabber cam;
    ofxDelaunay delaunay;
    ofVboMesh mesh;
};
