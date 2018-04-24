#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < 3; i++){
        pipes_vector.push_back(*new pipes);
    }
    
    ofSetWindowTitle("Flappy Bird");
    flappy.birdSetup(400, 400, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    flappy.gravity(gravity_value);
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBird();
    frame_counter++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_F12) {
        ofToggleFullscreen();
        return;
    }
    
    int upper_key = toupper(key);
    if(upper_key == ' '){
        flappy.fly(speed);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

void ofApp::drawPipes(){
    
}

void ofApp::drawBird(){
    ofSetColor(ofColor(50, 100, 50));
    ofDrawRectangle(flappy.getXCor(), flappy.getYCor(), 25, 25);
}
