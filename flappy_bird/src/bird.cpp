//
//  bird.cpp
//  flappy_bird
//
//  Created by Pradeep Kumar on 4/23/18.
//

#include "bird.hpp"

void bird::changeY(int y){
    y_cor += y;
}

void bird::birdSetup(int x, int y, int h, int w){
    bird::x_cor = x;
    bird::y_cor = y;
    height = h;
    width = w;
}

bool bird::isDead(int top_y, int bottom_y, int gapSize, int pipe_x){
    //Checks if bird is between the x corrdinates of the pipe
    if(x_cor >= pipe_x && x_cor <= (pipe_x+50)){
        //Checks if the bird is either in the top pipe or botton pipe.
        if((y_cor < top_y || y_cor >  bottom_y)){
            return true;
        }
    }
    return false;
}

void bird::fly(int strength){
    speed = -1 * strength;
}

void bird::gravity(int power){
    
    if(!(y_cor < 0 || y_cor > (height))){
        speed += power;
        changeY(speed);
    }else if (y_cor < 0){
        y_cor = height;
        //speed = 0;
    }else if (y_cor > (height)){
        y_cor = 0;
        //speed = 0;
    }
    
    if(speed > max_speed){
        speed = max_speed;
    }
    
}

int bird::getXCor(){
    return x_cor;
}

int bird::getYCor(){
    return y_cor;
}

int bird::getSpeed(){
    return speed;
}
