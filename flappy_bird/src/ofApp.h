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
    
    //Game Objects
    bird flappy;
    ofImage flappy_picture;
    
    std::vector<pipes> pipes_vector;
    std::vector<std::vector<ofImage>> pipes_images;
    
public:
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void resetVars();
    void addInitialPole();
    
    void removeTop();

};
