#pragma once

#include "ofMain.h"
#include "bird.hpp"
#include "pipes.hpp"
#include <vector>

class ofApp : public ofBaseApp{
    
    enum GameState{
        IN_PROGRESS,
        PAUSED,
        FINISHED
    };
    
private:
    ofSoundPlayer   mySound;
    
    //Highscore
    int highscore = 0;
    
    //Background
    ofImage background;
    
    //GameState
    GameState current_state = PAUSED;
    
    //Constants
    const int gravity_value = 2;
    const int speed = 29;
    const int spawn_time = 50;
    
    //Counters
    int wall_moveSpeed = 5;
    int number_of_pipes = 1;
    int spawn_timer = 0;
    
    //Functions
    void drawBird();
    void drawPipes();
    void resetVars();
    void addInitialPole();
    
    //Game Objects
    bird flappy;
    ofImage flappy_picture;
    string typeOfBird = "yellowbird";
    
    //Vectos.
    std::vector<pipes> pipes_vector;
    std::vector<std::vector<ofImage>> pipes_images;
    
    
public:
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
};
