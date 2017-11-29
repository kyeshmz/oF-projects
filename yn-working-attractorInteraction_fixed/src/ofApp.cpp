#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout << "setup begin";
    ofBackground(250,250,250);
    ofSetBackgroundAuto(false);
    
    
//    img.loadImage("basic_front.png");
//    fbo.allocate(img.getWidth(), img.getHeight(),GL_RGBA);
//    
//    fbo.begin();
//    {
//        ofClear(0,0,0,0);
//    }
//    fbo.end();
//    
//    fbo.begin();
//    {
//        ofClear(0,0,0,0);
//        //ofBackground(255,255,255);
//        ofSetColor(255);
//        ofDrawEllipse(100, 100, 50, 50);
//    }
//    fbo.end();
//    
//    img.getTexture().setAlphaMask(fbo.getTexture());
//    
//    
    // ofEnableSmoothing();
    // ofSetCircleResolution(65);
    
    playing = false;
    cell = 4;
    
    
    //POINTS
    //cell arguement here isnt working
    for (int j=0; j <=ofGetWidth(); j= j+cell) {
        for (int k=0; k<= ofGetHeight(); k= k + cell ) {
            //            ofVec2f p;
            //            p.set(j,k);
            //            pcoll.push_back(p);
            pcoll.push_back(ofVec2f(j,k));
        }
    }
    //    cout << "particles";
    //    for (int n=0; n < pcoll.size(); n++) {
    //        //ofVec2f particle;
    //        //particle.set(pcoll[n]);
    //        //        particle = particle + OrientorSortedCollection[j];
    //        ofFill();
    //        ofSetColor(0);
    //        ofFill();
    //        ofDrawCircle(pcoll[n].x, pcoll[n].y, 10);
    //        //ofDrawEllipse(pcoll[n].x,pcoll[n].y,5,5);
    //    }
    
    
    //
    gui.setup();
    ofColor initColor = ofColor(255, 127, 255, 255);
    ofColor minColor = ofColor(0,0,0,0);
    ofColor maxColor = ofColor(255,255,255,255);
    gui.add(color.setup("color", initColor, minColor, maxColor));
    gui.add(pradius.setup("radius", 0.1, 0, 10));
    gui.add(cellSize.setup("Cell Size", 10.0, 0, 100));
    
    
//    cell = cellSize;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    //    for (int i=0; i<pcoll.size(); i++) {
    //        ofVec2f target;
    //        for (int j=0; j<gravityPCollection.size(); j++) {
    ////            float disti = ofDist(pcoll[i].x, pcoll[i].y, gravityPCollection[j].x, gravityPCollection[j].y);
    //            float disti = pcoll[i].distance(gravityPCollection[j]);
    ////            ofVec2f vi = gravityPCollection[j] -
    //        }
    //    }
    
    
    //    for (int n=0; n < attractors.size(); n++) {
    //        ofFill();
    //        ofSetColor(255,128,144,255);
    //        ofDrawCircle(attractors[n].x, attractors[n].y, 10);
    //    }
    if (!playing) {
        for (int i=0; i<gravityPCollection.size(); i++) {
            ofSetColor(255, 0, 0);
            ofDrawCircle(gravityPCollection[i], 3);
        }
    } else {
        orientorCollection.resize(pcoll.size());
        distCollection.resize(pcoll.size());
        orientorCollection.clear();
        
        for (int n=0; n < pcoll.size(); n++) {
            ofVec2f particle;
            particle.set(pcoll[n]);
            ofVec2f target;
            
            for (int i=0; i <gravityPCollection.size(); i++) {
                float disti = particle.distance(gravityPCollection[i]);
                ofVec2f vi = gravityPCollection[i] - particle;
                vi.normalize();
                vi.scale(gravity[i]/disti);
                target = target + vi;
            }
            target.normalize();
            target.scale(0.5);
            orientorCollection[n]=target;
            pcoll.at(n) += target;
        }
        
        orientorSortedCollection.resize(pcoll.size());
        
//        for (int j=0; j< pcoll.size(); j++) {
//            ofVec2f temp;
//            temp.set(orientorCollection[j]);
//            temp.normalize();
//            temp.scale(2);
//            orientorSortedCollection[j] = temp;
//        }
        
        for (int j=0; j <pcoll.size(); j++) {
            ofSetColor(color);
            ofDrawCircle(pcoll.at(j), pradius);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p') {
        playing = !playing;
    }
    if (key == 's') {
        ofSaveFrame("moire-1.png");
    }
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
    ofVec2f pointSelect;
    pointSelect.set(x,y);
    cout << pointSelect;
    //    attractors.push_back(pointSelect);
    gravityPCollection.push_back(ofVec2f(x,y));
    gravity.push_back(ofRandom(20));
    //    gravityPCollection.push_back(attractors[y]);
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
