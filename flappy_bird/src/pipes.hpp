//
//  pipes.hpp
//  flappy_bird
//
//  Created by Pradeep Kumar on 4/24/18.
//

#ifndef pipes_hpp
#define pipes_hpp

#include <stdio.h>
#include "ofMain.h"


class pipes{
    
private:
    int x_cor;
    
    //Coordinates of pipes.
    int top_pipe_y;
    int bottom_pipe_y;
    
    int height;
    int width;
    
    const int gap_size=300;
    
    int randNum(int min, int max);
    
public:
    void pipeSetup(int h, int w, int x);
    void setup();
    void movePipe(int move_speed);
    
    //Getters
    int getXCor();
    int getTopPipe();
    int getBottomPipe();
    int getGapSize();

    
};

#endif /* pipes_hpp */
