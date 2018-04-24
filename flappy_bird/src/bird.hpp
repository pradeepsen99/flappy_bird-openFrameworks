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
    
    //Changes the x coordinate of the bird.
    void changeX(int value);
    
    //Changes the y coordinate of the bird.
    void changeY(int value);
    
public:
    //x, y variables that are the position.
    int xCor;
    int yCor;
    
    //The constructor.
    void birdSetup(int x, int y);
    
    //Moving the bird variables.
    void fly(int strength);
    
    //Gravity
    void gravity(int power);
};


#endif /* bird_hpp */
