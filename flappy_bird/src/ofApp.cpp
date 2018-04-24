#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i = 0; i < 3; i++){
        pipes_vector.push_back(*new pipes);
    }
    
    
    ofSetWindowTitle("Flappy Bird");
    flappy.birdSetup(400, 400);
}

//--------------------------------------------------------------
void ofApp::update(){
    flappy.gravity(2);
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBird();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_F12) {
        ofToggleFullscreen();
        return;
    }
    
    int upper_key = toupper(key);
    if(upper_key == ' '){
        flappy.fly(20);
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
    ofDrawRectangle(flappy.getYCor(), flappy.getXCor(), 25, 25);
}
