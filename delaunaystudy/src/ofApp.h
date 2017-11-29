#pragma once

#include "ofMain.h"

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
		
};
class TrianglePoints
{
public:
    TrianglePoints(int t1,
                   int t2,
                   int t3);
    void setup0(int t1,
                int t2,
                int t3);
    int tri1;
    int tri2;
    int tri3;
protected:
private:
};

class LinePoints
{
public:
    LinePoints(int l1,int l2);
    void setup0(int l1,int l2);
    int li1;
    int li2;
protected:
private:
};
