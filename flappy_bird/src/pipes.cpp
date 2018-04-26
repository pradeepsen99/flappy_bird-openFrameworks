//
//  pipes.cpp
//  flappy_bird
//
//  Created by Pradeep Kumar on 4/24/18.
//

#include "pipes.hpp"

void pipes::pipeSetup(int h, int w, int x){
    height = h;
    width = w;
    x_cor = x;
    
    //Sets up the pipe structure.
    
}

void pipes::movePipe(int move_speed){
    x_cor -= move_speed;
}

//Taken From http://www.cplusplus.com/forum/beginner/183358/
int pipes::randNum(int min, int max)
{
    int x = rand() % min +  max;
    return x;
}

