#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout << "setup begin";
    ofBackground(250,250,250);
    ofSetBackgroundAuto(false);
   // ofEnableSmoothing();
   // ofSetCircleResolution(65);
    num_attractors = 20;
    cell = 10;
    playing = false;
    
    gravityPCollection.resize(num_attractors);
    gravity.resize(num_attractors);
    pcoll.resize(ofGetHeight()*2);
    attractors.resize(10);
    
    
    
    //point attractor
//    for (int y=0; y< num_attractors; y++) {
//        // no viable conversion for the assignment
//        //figure out why I need a star before this arguement
//        
//        gravityPCollection[y] = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//        gravity[y] = ofRandom(10);
//    }
    
    //POINTS
    //cell arguement here isnt working
    for (int j=0; j <=ofGetWidth(); j= j+cell) {
        for (int k=0; k<= ofGetHeight(); k= k + cell ) {
            ofVec2f p;
            p.set(j,k);
            
            //cout << pcoll.size();
            pcoll.push_back(p);
          //  pcoll.assign(pcoll.size(),ofVec2f(j,k));
        }
    }
    cout << "particles";
    for (int n=0; n < pcoll.size(); n++) {
        //ofVec2f particle;
        //particle.set(pcoll[n]);
        //        particle = particle + OrientorSortedCollection[j];
        ofFill();
        ofSetColor(0);
        ofFill();
        ofDrawCircle(pcoll[n].x, pcoll[n].y, 10);
        //ofDrawEllipse(pcoll[n].x,pcoll[n].y,5,5);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int n=0; n < attractors.size(); n++) {
        ofFill();
        ofSetColor(255,128,144,255);
        ofDrawCircle(attractors[n].x, attractors[n].y, 10);
    }
    if (playing == true){
    orientorCollection.resize(pcoll.size());
    distCollection.resize(pcoll.size());
    
    
    for (int n=0; n < pcoll.size(); n++) {
       ofVec2f particle;
        particle.set(pcoll[n]);
        ofVec2f target;
        
        for (int i=0; i <num_attractors; i++) {
            float disti = particle.distance(gravityPCollection[i]);
            ofVec2f vi = gravityPCollection[i] - particle;
            vi.normalize();
            vi.scale(gravity[i]/disti);
            target = target + vi;
        }
        target.normalize();
        target.scale(5);
        orientorCollection[n]=target;
    }
    
    orientorSortedCollection.resize(pcoll.size());
    
    for (int j=0; j< pcoll.size(); j++) {
        ofVec2f temp;
        temp.set(orientorCollection[j]);
        temp.normalize();
        temp.scale(0.1);
        orientorSortedCollection[j] = temp;
    }
    
for (int j=0; j <pcoll.size(); j++) {
//    ofVec2f particle;
//    particle.set(pcoll[j]);
//    particle = particle + orientorSortedCollection[j];
    pcoll[j] += orientorSortedCollection[j];
    ofFill();
    ofDrawCircle(pcoll[j], 1);
    //this one doesnt
//    ofDrawEllipse(particle.x, particle.y, 20, 20);
    //this bottom one works
   // ofDrawEllipse(pcoll[j].x, pcoll[j].y, 10, 10);
    
    
}
}
////        particle = particle + OrientorSortedCollection[j];
//        ofFill();
//        ofSetColor(250,128,114,255);
//        ofDrawEllipse(particle.x,particle.y,1,1);
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p') {
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
    cout << pointSelect;
    attractors.push_back(pointSelect);
    gravity.push_back(ofRandom(100));

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
