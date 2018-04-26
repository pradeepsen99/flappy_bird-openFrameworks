#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //BACKGROUND stuff.
    ofSetBackgroundAuto(true);
    background.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/background-day.png");
    flappy_picture.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/yellowbird-downflap.png");
    
    
    
    for(int i = 0; i < number_of_pipes; i++){
        pipes_vector.push_back(*new pipes);
        pipes_vector[i].pipeSetup(ofGetHeight(), ofGetWidth(), ofGetWidth());
        
        for(int j = 0; j < 2; j++){
            ofImage pipeImg;
            pipeImg.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/pipe-green.png");
            pipes_images[i].push_back(pipeImg);
        }
        
        ofSetWindowTitle("Flappy Bird");
        flappy.birdSetup(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight(), ofGetWidth());
    }
}
    
    //--------------------------------------------------------------
    void ofApp::update(){
        flappy.gravity(gravity_value);
    }
    
    //--------------------------------------------------------------
    void ofApp::draw(){
        background.draw(0, 0, ofGetWidth(), ofGetHeight());
        drawBird();
        for(int i = 0; i < 3; i++){
            //pipes_vector[i].drawPipe();
        }
        string message = "fps: "+ofToString(ofGetFrameRate());
        ofDrawBitmapString(message, 10, 20);
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
        for(int i = 0; i < number_of_pipes; i++){
            
        }
    }
    
    void ofApp::drawBird(){
        //ofSetColor(ofColor(50, 100, 50));
        //ofDrawRectangle(flappy.getXCor(), flappy.getYCor(), 25, 25);
        flappy_picture.draw(flappy.getXCor(), flappy.getYCor(), 50,50);
        
    }
