#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

void ofApp::setup() {
    rgb.loadImage("4444.jpg");
    
}

void ofApp::update() {
    //delaunay.reset();
    //    mesh.clear();
    
    convertColor(rgb, gray, CV_RGB2GRAY);
    blur(gray, 4);
    Canny(gray, edge, 20, 100);
    gray.update();
    edge.update();
    dilate(edge);
    unsigned char *edgeData = edge.getPixels().getData();
    
    
    int up = 45;
    for (int i=0; i < w*h; i+=up) {
        if (edgeData[i] == 0) {
            continue;
        }
        else {
            int coordY = floor(i/w);
            mesh.addVertex(ofVec2f(i-w*coordY, coordY));
            delaunay.addPoint(ofVec2f(i-w*coordY, coordY));
        }
    }
    
    delaunay.addPoint(ofPoint(0, 0));
    delaunay.addPoint(ofPoint(0, h));
    delaunay.addPoint(ofPoint(w, h));
    delaunay.addPoint(ofPoint(w, 0));
    
    delaunay.triangulate();
    
    
    //use the color of the center of the polygon
    
    ofPixels pixels = rgb.getPixelsRef();
    for (int i=0; i<delaunay.triangleMesh.getNumIndices()/3; i++) {
        int idx1 = delaunay.triangleMesh.getIndex(i*3);
        int idx2 = delaunay.triangleMesh.getIndex(i*3+1);
        int idx3 = delaunay.triangleMesh.getIndex(i*3+2);
        
        ofVec2f v1 = delaunay.triangleMesh.getVertex(idx1);
        ofVec2f v2 = delaunay.triangleMesh.getVertex(idx2);
        ofVec2f v3 = delaunay.triangleMesh.getVertex(idx3);
        
        ofVec2f gp = (v1+v2+v3)/3.0;
        
        ofColor color = pixels.getColor((int)gp.x, (int)gp.y);
        
        mesh.addVertex(v1);
        mesh.addVertex(v2);
        mesh.addVertex(v3);
        
        mesh.addColor(color);
        mesh.addColor(color);
        mesh.addColor(color);
    }

    
}

void ofApp::draw() {
    rgb.draw(0, 0);
    gray.draw(463, 0);
    edge.draw(463*2, 0);
    
    ofPushMatrix();
    ofTranslate(0, 410);
    rgb.draw(0, 0);
    mesh.drawVertices();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(463, 410);
    rgb.draw(0, 0);
    ofNoFill();
    delaunay.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(463*2, 410);
//    ofFill();
//    delaunay.draw();
    ofPopMatrix();
}
