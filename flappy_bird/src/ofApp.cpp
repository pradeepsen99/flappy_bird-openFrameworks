#include "ofApp.h"

//--------------------------------------------------------------
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

//--------------------------------------------------------------
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
    mySound.load("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/audio/wing.wav");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(current_state == IN_PROGRESS){
        //Adds the gravity element into the game.
        flappy.gravity(gravity_value);
        
        //Moves the wall a certain amount to the left. Increasing value makes it goes faster.
        for(int i = 0; i < pipes_vector.size(); i++){
            pipes_vector[i].movePipe(wall_moveSpeed);
        }
        
        //Every time spawn timer reaches 30, it spawns a new pipe.
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
        
        //Animations that are based off of the speed of the bird.
        if(flappy.getSpeed() > 0){
            flappy_picture.loadImage(ofToString("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/") + typeOfBird+ "-upflap.png");
        }else if(flappy.getSpeed()<0){
            flappy_picture.loadImage(ofToString("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/") + typeOfBird+ "-downflap.png");
        }else if(flappy.getSpeed() == 0){
            flappy_picture.loadImage(ofToString("/Users/pradeepkumar/Desktop/Spring_2018/CS_126/final-project-pradeepsen99/flappy_bird/src/assets/sprites/") + typeOfBird+ "-midflap.png");
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    drawBird();
    drawPipes();
    
    
    if(current_state == FINISHED){
        ofDrawBitmapString("PRESS SPACE TO START", 258, 384);
    }else if(current_state == PAUSED){
        ofDrawBitmapString("GAME IS PAUSED\nHIGHSCORE: " + ofToString(highscore), 258, 384);
    }
    
    //FPS Counter.
    string message = "fps: "+ofToString(ofGetFrameRate()) + " Score " + ofToString(pipes_vector.size());
    ofDrawBitmapString(message, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int upper_key = toupper(key);
    //Q changes the color of the birds
    if(upper_key == 'Q'){
        if(typeOfBird == "yellowbird"){
            typeOfBird = "redbird";
        }else if(typeOfBird == "redbird"){
            typeOfBird = "yellowbird";
        }
    }
    
    if(upper_key == ' '){
        flappy.fly(speed);
        //This starts the game
        if(current_state == PAUSED){
            current_state = IN_PROGRESS;
        }
        //Makes the flapping noises
        mySound.play();
    }else if(upper_key == 'R' && current_state == FINISHED){
        resetVars();
        addInitialPole();
    }
    
}

//--------------------------------------------------------------
void ofApp::drawPipes(){
    for(int i = 0; i < pipes_vector.size(); i++){
        //Collision detection
        if(flappy.isDead(pipes_vector[i].getTopPipe(), pipes_vector[i].getBottomPipe(), pipes_vector[i].getGapSize(), pipes_vector[i].getXCor())){
            if(highscore < pipes_vector.size()){
                highscore = pipes_vector.size();
            }
            wall_moveSpeed = 0;
            current_state = FINISHED;
        }
        //Rendering pipes
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
    flappy_picture.draw(flappy.getXCor(), flappy.getYCor(), 50,50);
}




