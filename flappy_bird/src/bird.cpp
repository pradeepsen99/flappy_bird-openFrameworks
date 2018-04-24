//
//  bird.cpp
//  flappy_bird
//
//  Created by Pradeep Kumar on 4/23/18.
//

#include "bird.hpp"


void bird::birdSetup(int x, int y){
    bird::xCor = x;
    bird::yCor = y;
}

void bird::fly(int strength){
    changeX(strength);
    //TODO Add animations here.
}

void bird::gravity(int power){
    changeX(power);
}


