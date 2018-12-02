//
//  board.hpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <stdio.h>

class board {
    friend class ai;
protected:
    int player_node[6][42];
    int player_node_count[6];
    int node[42][2];
    int node_node[42][7]; //static
    int node_node_count[42]; //static
    int node_node_pos[42][42]; //static
    int node_node_moves[42][7];
    int node_node_moves_count[42];
    int player_move_count[6];
    
    
public:
    board();
    int * legal_moves(int player);
    
};


#endif /* board_hpp */
