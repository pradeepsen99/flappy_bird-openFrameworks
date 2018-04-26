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

void bird::fly(int strength){
    speed = -1 * strength;
    //changeX(strength * -1);
    //TODO Add animations here.
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
