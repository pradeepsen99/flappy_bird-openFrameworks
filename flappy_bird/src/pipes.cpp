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
    srand(time(NULL));
    int halfway_point = (h/2);
    top_pipe_y = randNum(1, halfway_point-100);
    bottom_pipe_y = top_pipe_y + gap_size;
    
}

void pipes::movePipe(int move_speed){
    x_cor -= move_speed;
    if(x_cor < 0){
        x_cor = width;
    }
}

//Taken From http://www.cplusplus.com/forum/beginner/183358/
int pipes::randNum(int min, int max)
{
    return rand() % min +  max;
    //return x;
}

int pipes::getBottomPipe(){
    return bottom_pipe_y;
}

int pipes::getTopPipe(){
    return top_pipe_y;
}

int pipes::getXCor(){
    return x_cor;
}



