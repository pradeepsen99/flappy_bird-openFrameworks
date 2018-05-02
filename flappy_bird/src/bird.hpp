//
//  bird.hpp
//  flappy_bird
//
//  Created by Pradeep Kumar on 4/23/18.
//

#ifndef bird_hpp
#define bird_hpp

#include <stdio.h>

class bird{
private:
    //speed var, influenced by gravity
    int speed = 0;
    const int max_speed = 50;
    
    //x, y variables that are the position.
    int x_cor;
    int y_cor;
    const int height_buffer = 300;
    
    //Height and width of the screen.
    int height;
    int width;
    
    //Changes the x coordinate of the bird.
    void changeX(int value);
    
    //Changes the y coordinate of the bird.
    void changeY(int value);
    
public:
    //Getter
    int getXCor();
    int getYCor();
    int getSpeed();
    
    //The constructor.
    void birdSetup(int x, int y, int h, int w);
    
    //Moving the bird variables.
    void fly(int strength);
    
    //Gravity
    void gravity(int power);
    
    //Dead?
    bool isDead(int top_y, int bottom_y, int gapSize, int pipe_x);
    
};


#endif /* bird_hpp */
