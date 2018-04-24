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
    bird flappy;
    
    GameState current_state = IN_PROGRESS;
    
    int gravity_value = 0;
    int speed = 5;
    int wall_moveSpeed = 5;
    
    //Functions
    void drawBird();
    void drawPipes();
    
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
