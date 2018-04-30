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
        
        pipes_images.push_back(*new std::vector<ofImage>);
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
    for(int i = 0; i < number_of_pipes; i++){
        pipes_vector[i].movePipe(wall_moveSpeed);
    }
    spawn_timer++;
    if(spawn_timer == spawn_time){
        pipes_vector.push_back(*new pipes);
        
        std::vector<ofImage> current_image;
        for(int j = 0; j < 2; j++){
            ofImage pipeImg;
            pipeImg.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/pipe-green.png");
            current_image.push_back(pipeImg);
        }
        pipes_images.push_back(current_image);
        number_of_pipes++;
        spawn_timer = 0;
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    drawBird();
    drawPipes();

    //FPS Counter.
    string message = "fps: "+ofToString(ofGetFrameRate()) + " NumberOfPipes " + ofToString(pipes_vector.size());
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
void ofApp::drawPipes(){
    for(int i = 0; i < number_of_pipes; i++){
        for(int j = 0; j < 2; j++){
            if(j==0){
                //                    ofPushMatrix();
                //                    ofTranslate(50/2, pipes_vector[i].getTopPipe()/2, 0);
                //                    ofRotate(180);
                pipes_images[i].at(j).draw(pipes_vector[i].getXCor(), 0, 50, pipes_vector[i].getTopPipe());
                //                    ofPopMatrix();
                //                    ofTranslate(0,0);
            }else if(j==1){
                pipes_images[i].at(j).draw(pipes_vector[i].getXCor(), (ofGetHeight()-(ofGetHeight()/4)), 50, pipes_vector[i].getBottomPipe());
            }
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawBird(){
    //ofSetColor(ofColor(50, 100, 50));
    //ofDrawRectangle(flappy.getXCor(), flappy.getYCor(), 25, 25);
    flappy_picture.draw(flappy.getXCor(), flappy.getYCor(), 50,50);
    
}
