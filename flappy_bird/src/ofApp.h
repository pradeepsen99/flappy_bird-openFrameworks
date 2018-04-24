#pragma once

#include "ofMain.h"
#include "bird.hpp"
#include "pipes.hpp"

class ofApp : public ofBaseApp{
    
    enum GameState{
        IN_PROGRESS = 0,
        PAUSED,
        FINISHED
    };
    
private:
    //Testing variables
    int frame_counter = 0;
    
    //GameState
    GameState current_state = IN_PROGRESS;
    
    //Constants
    const int gravity_value = 2;
    const int speed = 29;
    const int wall_moveSpeed = 5;
    
    //Functions
    void drawBird();
    void drawPipes();
    
    //Game Objects
    bird flappy;
    std::vector<pipes> pipes_vector;
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    /*void mouseDragged(int x, int y, int button);
     void mousePressed(int x, int y, int button);
     void mouseReleased(int x, int y, int button);
     void mouseEntered(int x, int y);
     void mouseExited(int x, int y);
     void windowResized(int w, int h);
     void dragEvent(ofDragInfo dragInfo);
     void gotMessage(ofMessage msg);*/
    
};
