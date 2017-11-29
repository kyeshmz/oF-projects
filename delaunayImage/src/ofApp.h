#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDelaunay.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    
    ofImage rgb, gray, edge;
    ofVboMesh mesh;
    ofxDelaunay delaunay;
    
    int w = 463;
    int h = 441;
};
