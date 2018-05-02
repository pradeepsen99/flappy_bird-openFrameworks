#include "ofApp.h"

void ofApp::resetVars(){
    //Resetting Variables
    pipes_vector.clear();
    pipes_images.clear();
    number_of_pipes == 1;
    current_state = IN_PROGRESS;
    wall_moveSpeed = 5;
    number_of_pipes = 1;
    spawn_timer = 0;
    current_state = PAUSED;
    flappy.birdSetup(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight(), ofGetWidth());
}

void ofApp::addInitialPole(){
    for(int i = 0; i < number_of_pipes; i++){
        pipes_vector.push_back(*new pipes);
        pipes_vector[i].pipeSetup(ofGetHeight(), ofGetWidth(), ofGetWidth());
        
        pipes_images.push_back(*new std::vector<ofImage>);
        for(int j = 0; j < 2; j++){
            ofImage pipeImg;
            pipeImg.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/pipe-green.png");
            pipes_images[i].push_back(pipeImg);
        }
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //BACKGROUND stuff.
    ofSetBackgroundAuto(true);
    background.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/background-day.png");
    
    //Bird
    flappy_picture.loadImage("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/yellowbird-downflap.png");
    flappy.birdSetup(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight(), ofGetWidth());
    
    //Window Title
    ofSetWindowTitle("Flappy Bird");
    
    addInitialPole();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(current_state == IN_PROGRESS){
        flappy.gravity(gravity_value);
        for(int i = 0; i < pipes_vector.size(); i++){
            pipes_vector[i].movePipe(wall_moveSpeed);
        }
        spawn_timer++;
        if(spawn_timer == spawn_time){
            
            pipes_vector.push_back(*new pipes);
            pipes_vector[number_of_pipes].pipeSetup(ofGetHeight(), ofGetWidth(), ofGetWidth());
            
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
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    drawBird();
    drawPipes();
    
    if(current_state == FINISHED){
        ofDrawBitmapString("YOU LOST", 258, 384);
    }
    
    //FPS Counter.
    string message = "fps: "+ofToString(ofGetFrameRate()) + " Score " + ofToString(pipes_vector.size());
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
        if(current_state == PAUSED){
            current_state = IN_PROGRESS;
        }
    }else if(upper_key == 'R' && current_state == FINISHED){
        resetVars();
        addInitialPole();
    }else if(upper_key == ' '){
        
    }
    
}

//--------------------------------------------------------------
void ofApp::drawPipes(){
    for(int i = 0; i < pipes_vector.size(); i++){
        if(pipes_vector[i].getXCor() < 0){
            //pipes_vector.pop_back();
            //number_of_pipes--;
            //removeTop();
        }
        //Collision detection
        if(flappy.isDead(pipes_vector[i].getTopPipe(), pipes_vector[i].getBottomPipe(), pipes_vector[i].getGapSize(), pipes_vector[i].getXCor())){
            wall_moveSpeed = 0;
            current_state = FINISHED;
        }
        for(int j = 0; j < 2; j++){
            if(j==0){
                pipes_images[i].at(j).draw(pipes_vector[i].getXCor(), 0, 50, pipes_vector[i].getTopPipe());
            }else if(j==1){
                pipes_images[i].at(j).draw(pipes_vector[i].getXCor(), pipes_vector[i].getBottomPipe(), 50, 900);
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

void ofApp::removeTop(){
    //pipes_vector.erase(pipes_vector.begin());
    number_of_pipes--;
}







