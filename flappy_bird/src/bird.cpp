//
//  bird.cpp
//  flappy_bird
//
//  Created by Pradeep Kumar on 4/23/18.
//

#include "bird.hpp"

void bird::changeX(int x){
    xCor += x;
}

void bird::birdSetup(int x, int y){
    bird::xCor = x;
    bird::yCor = y;
}

void bird::fly(int strength){
    speed = -1*strength;
    //changeX(strength * -1);
    //TODO Add animations here.
}

void bird::gravity(int power){
    speed += power;
    changeX(speed);
}

int bird::getXCor(){
    return xCor;
}

int bird::getYCor(){
    return yCor;
}
