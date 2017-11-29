#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    Boolean playing;
    int cell = 1;
    vector <ofVec2f> pcoll;
    vector <ofVec2f> orientorSortedCollection;
    vector <ofVec2f> gravityPCollection;
    vector <ofVec2f> orientorCollection;
    vector <float> gravity;
    vector <float> distCollection;
    ofMesh mesh;
    ofImage img;
    ofPath path;
    ofFbo fbo;
    
    //GUI
    ofxPanel gui;
    ofxColorSlider color;
    ofxFloatSlider pradius;
    ofxIntSlider cellSize;
    
    
    
};
