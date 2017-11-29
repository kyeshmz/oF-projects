#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cout << "setup begin";
    ofBackground(250,250,250);
   // ofEnableSmoothing();
   // ofSetCircleResolution(65);
    ofSetBackgroundAuto(false);
    num_attractors = 20;
    cell = 10;
    
    gravityPCollection.resize(num_attractors);
    gravity.resize(attractors.size());
    pcoll.resize(ofGetHeight()*2);
    
    
    
    //point attractor
    for (int y=0; y< attractors.size(); y++) {
        // no viable conversion for the assignment
        //figure out why I need a star before this arguement
       // attractors[y] = *new ofVec2f(attractors[y].x,attractors[y].y);
        gravityPCollection[y] = *new ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        gravity[y] = ofRandom(1,100);
    }
    
    //POINTS
    //cell arguement here isnt working
    for (int j=0; j <=ofGetWidth(); j= j+cell) {
        for (int k=0; k<= ofGetHeight(); k= k + cell ) {
            ofVec2f p;
            p.set(j,k);
            
          //  cout << pcoll.size();
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
        ofSetColor(250,128,255,255);
        ofFill();
        ofVbo myVbo;
        //myVbo.setVertexData(&pcoll[n], pcoll.size(), GL_DYNAMIC_DRAW);
        //ofDrawCircle(pcoll[n].x, pcoll[n].y, 10);
        //ofDrawEllipse(pcoll[n].x,pcoll[n].y,5,5);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    orientorCollection.resize(pcoll.size());
    orientorSortedCollection.resize(pcoll.size());
    distCollection.resize(pcoll.size());
    
    
    for (int n=0; n < pcoll.size(); n++) {
        ofVec2f target;
        
        for (int i=0; i <attractors.size(); i++) {
            float disti = pcoll[n].distance(gravityPCollection[i]);
           // float disti = particle.distance(gravityPCollection[i]);
            ofVec2f vi = gravityPCollection[i] - pcoll[n];
            vi.normalize();
            vi.scale(gravity[i]/disti);
            target = target + vi;
            
         }
        target.normalize();
        target.scale(5);
        orientorCollection[n]=target;
    }
    
    for (int j=0; j< pcoll.size(); j++) {
        ofVec2f temp;
        temp.set(orientorCollection[j]);
        temp.normalize();
        temp.scale(3);
        orientorSortedCollection[j] = temp;
    }
    
for (int j=0; j <pcoll.size(); j++) {
    ofVec2f particle;
    particle.set(pcoll[j]);
    particle = particle + orientorSortedCollection[j];
    ofFill();
    ofColor(255,128,114,255);
    //this one doesnt
    ofDrawEllipse(particle.x, particle.y, 4, 4);
    //this bottom one works
    //ofDrawEllipse(pcoll[j].x, pcoll[j].y, 10, 10);
    
    
}
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
