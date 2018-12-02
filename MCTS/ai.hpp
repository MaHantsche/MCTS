//
//  ai.hpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#ifndef ai_hpp
#define ai_hpp

#include <stdio.h>
#include "board.hpp"

class ai {
private:
    long random_seq[100][100];
public:
    void initailize_board_random(board &b, int player);
    void set_random_sequence();
};

#endif /* ai_hpp */
