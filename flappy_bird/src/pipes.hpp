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
    
    int top_pipe_y;
    int bottom_pipe_y;
    
    const int gap_size=200;
    
public:
    void pipeSetup(int h, int w, int x);
    
    void setup();
    int getYCor();
    void movePipe(int move_speed);
    void drawPipe();
    
};

#endif /* pipes_hpp */
