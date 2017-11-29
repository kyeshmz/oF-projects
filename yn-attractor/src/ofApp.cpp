#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(250,250,250);
    ofSetBackgroundAuto(false);
    recording = true;
    playing = false;
    cell = 30;
//    orientorCollection.resize(gridPoints.size());
//    orientorSortedCollection.resize(gridPoints.size());
//    gravityPCollection.resize(attractors.size());

    
    //grid of points layed out x and y
    for (int j=0; j <=ofGetWidth(); j= j+cell) {
        for (int k=0; k<= ofGetHeight(); k= k + cell ) {
            ofVec2f gridPoint;
            gridPoint.set(j,k);
            
            //  cout << pcoll.size();
            gridPoints.push_back(gridPoint);
           // gridPoints.resize(ofGetHeight()*2);
        }
    }
    
    orientorCollection.resize(gridPoints.size(), ofVec2f(0,0));
    orientorSortedCollection.resize(gridPoints.size(), ofVec2f(0,0));
    gravityPCollection.resize(gridPoints.size(), ofVec2f(0,0));
    
    //setting  the attractor position
//    for (int y=0; y< attractors.size(); y++) {
//        attractors[y] = *new ofVec2f(attractors[y].x,attractors[y].y);
//        // gravityPCollection[y] = *new ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//        gravity[y] = ofRandom(1,100);
//    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (playing == false) {
        //draw the grid points layed out x and y
        for (int i=0; i < gridPoints.size(); i++) {
            ofSetColor(255,128,114,255);
            ofDrawCircle(gridPoints[i].x,gridPoints[i].y, 3);
        }
        //drawing the attractor position
        for (int n=0; n < attractors.size(); n++) {
            ofFill();
            ofSetColor(255,128,144,255);
            ofDrawCircle(attractors[n].x, attractors[n].y, 10);
        }
        
        for (int y=0; y< attractors.size(); y++) {
            gravityPCollection[y] =  ofVec2f(attractors[y]);
            
            
            // gravityPCollection[y] = *new ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//            gravity[y] = ofRandom(10);
        }
    }
    
    if (playing == true) {
        cout << ofGetFrameNum() << endl;
        recording = !recording;
        //draw the colored points inside of the grid
        for (int z=0; z < gridPoints.size(); z++) {
//            ofFill();
            ofSetColor(255,128,114,255);
            ofDrawCircle(gridPoints[z].x,gridPoints[z].y, 2);
        }
//        //setting  the attractor position
//        for (int y=0; y< attractors.size(); y++) {
//            attractors[y] = *new ofVec2f(attractors[y].x,attractors[y].y);
//            // gravityPCollection[y] = *new ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//            gravity[y] = ofRandom(1,100);
//        }
        
        for (int m=0; m < gridPoints.size(); m++) {
            ofVec2f target;
            ofVec2f particle;
            particle.set(gridPoints[m]);
            for (int a=0; a<attractors.size(); a++) {
                float disti = particle.distance(gravityPCollection[a]);
                //grid points m as particle
                ofVec2f vi = gravityPCollection[a] - gridPoints[m];
                vi.normalize();
//               cout << vi;
                vi.scale(gravity[a]/disti);
                target = target + vi;
            }
            target.normalize();
            target.scale(5);
            orientorCollection[m] = target;
        }
        
        for (int j=0; j< gridPoints.size(); j++) {
            ofVec2f temp;
            temp.set(orientorCollection[j]);
            temp.normalize();
            temp.scale(3);
            orientorSortedCollection[j] = temp;
        }
        
        for (int k=0; k<gridPoints.size(); k++) {
            ofVec2f particle;
            particle.set(gridPoints[k]);
            pcoll += orientorSortedCollection[k];
            ofFill();
//            ofColor(255,128,114,255);
            ofColor(255, 0, 0, 255);
            ofDrawCircle(gridPoints[k].x, gridPoints[k].y, 10);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'k') {
        playing = !playing;
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
        cout << pointSelect <<"\n";
        attractors.push_back(pointSelect);
        gravity.push_back(ofRandom(100));
        for (int n=0; n<attractors.size();n++){
            gravityPCollection.push_back(attractors[n]);
//         ofDrawCircle(attractors[n].x, attractors[n].y, 10);
        }

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
