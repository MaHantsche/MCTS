//
//  board.hpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

//#ifndef board_hpp
//#define board_hpp

//#include <stdio.h>

//class board {
//    friend class ai;
//protected:
//    unsigned char player_node[6][42];  //players and there nodes
//    unsigned char player_node_count[6]; //number of nodes per player
//    unsigned char node[42][2]; //nodes player and infantry units
//    const unsigned char node_node[42][6]={
//        {1,3,29,100,100,100}, //0
//        {0,2,3,4,100,100},
//        {1,4,5,19,100,100},
//        {0,1,4,6,100,100},
//        {1,2,3,5,6,7}, //4
//        {2,4,7,100,100,100},
//        {3,4,7,8,100,100},
//        {4,5,6,8,100,100},
//        {6,7,9,100,100,100},
//        {8,10,11,100,100,100}, //9
//        {9,11,12,13,100,100},
//        {9,10,12,100,100,100},
//        {10,11,100,100,100,100},
//        {10,14,15,16,24,25},
//        {13,16,25,35,100,100}, //14
//        {13,16,17,100,100,100},
//        {13,14,15,17,18,35},
//        {15,16,18,100,100,100},
//        {16,17,100,100,100,100},
//        {2,20,21,100,100,100}, //19
//        {19,21,22,23,100,100},
//        {19,20,22,24,100,100},
//        {20,21,23,24,25,100},
//        {20,22,25,26,32,35},
//        {21,22,25,13,100,100}, //24
//        {22,23,24,13,14,35},
//        {23,27,32,33,100,100},
//        {26,28,30,33,34,100},
//        {27,29,30,100,100,100},
//        {0,28,30,31,100,100}, //29
//        {27,28,29,31,34,100},
//        {29,30,34,100,100,100},
//        {23,26,33,35,36,100},
//        {26,27,32,34,36,37},
//        {27,30,31,33,100,100}, //34
//        {14,16,23,25,32,36},
//        {32,33,35,37,100,100},
//        {33,36,38,100,100,100},
//        {37,39,40,100,100,100},
//        {38,40,41,100,100,100}, //39
//        {38,39,41,100,100,100},
//        {39,40,100,100,100,100}
//    }; //fix: nodes and their connected nodes
//    unsigned char node_node_count[42]; //fix: number of connected nodes per node
//    unsigned char node_node_pos[42][42]; //fix: position of node to node connection in the node_node array
//    unsigned char node_node_moves[42][7]; //nodes and their connected nodes which allow a move (start node has more than 2 infantry units and end node belongs to another player (legal moves per node)
//    unsigned char node_node_moves_count[42]; //number of legal moves per node
//    unsigned char player_move_count[6]; //number of legal moves per player
//    
//    
//public:
//    board(); //initialize board
//    void get_moves_count();
//    void get_player_moves_count();
//    void get_nodes();
//    
//    //unsigned char** legal_moves(unsigned char player);
//    
//};
//
//
//#endif /* board_hpp */
