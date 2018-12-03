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
    int player_node[6][42];  //players and there nodes
    int player_node_count[6]; //number of nodes per player
    int node[42][2]; //nodes player and infantry units
    int node_node[42][6]={
        {1,3,29,-1,-1,-1}, //0
        {0,2,3,4,-1,-1},
        {1,4,5,19,-1,-1},
        {0,1,4,6,-1,-1},
        {1,2,3,5,6,7}, //4
        {2,4,7,-1,-1,-1},
        {3,4,7,8,-1,-1},
        {4,5,6,8,-1,-1},
        {6,7,9,-1,-1,-1},
        {8,10,11,-1,-1,-1}, //9
        {9,11,12,13,-1,-1},
        {9,10,12,-1,-1,-1},
        {10,11,-1,-1,-1,-1},
        {10,14,15,16,24,25},
        {13,16,25,35,-1,-1}, //14
        {13,16,17,-1,-1,-1},
        {13,14,15,17,18,35},
        {15,16,18,-1,-1,-1},
        {16,17,-1,-1,-1,-1},
        {2,20,21,-1,-1,-1}, //19
        {19,21,22,23,-1,-1},
        {19,20,22,24,-1,-1},
        {20,21,23,24,25,-1},
        {20,22,25,26,32,35},
        {21,22,25,13,-1,-1}, //24
        {22,23,24,13,14,35},
        {23,27,32,33,-1,-1},
        {26,28,30,33,34,-1},
        {27,29,30,-1,-1,-1},
        {0,28,30,31,-1,-1}, //29
        {27,28,29,31,34,-1},
        {29,30,34,-1,-1,-1},
        {23,26,33,35,36,-1},
        {26,27,32,34,36,37},
        {27,30,31,33,-1,-1}, //34
        {14,16,23,25,32,36},
        {32,33,35,37,-1,-1},
        {33,36,38,-1,-1,-1},
        {37,39,40,-1,-1,-1},
        {38,40,41,-1,-1,-1}, //39
        {38,39,41,-1,-1,-1},
        {39,40,-1,-1,-1,-1}
    }; //fix: nodes and their connected nodes
    int node_node_count[42]; //fix: number of connected nodes per node
    int node_node_pos[42][42]; //fix: position of node to node connection in the node_node array
    int node_node_moves[42][7]; //nodes and their connected nodes which allow a move (start node has more than 2 infantry units and end node belongs to another player (legal moves per node)
    int node_node_moves_count[42]; //number of legal moves per node
    int player_move_count[6]; //number of legal moves per player
    
    
public:
    board(); //initialize board
    void get_moves_count();
    void get_player_moves_count();
    void get_nodes();
    int * legal_moves(int player);
    
};


#endif /* board_hpp */
