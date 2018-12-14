//
//  functions.hpp
//  MCTS
//
//  Created by Marcel Hantsche on 11.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <array>

#endif /* functions_hpp */


struct sboard{
    //std::array<std::array<unsigned char,42>,6> player_node;
    std::array<std::array<unsigned char,42>,2> node;
    //std::array<unsigned char,6> player_node_count; //number of nodes per player
    //unsigned char node_node_pos[42][42]; //fix: position of node to node connection in the node_node array
    //std::array<std::array<unsigned char,7>,42> node_node_moves; //nodes and their connected nodes which allow a move (start node has more than 2 infantry units and end node belongs to another player (legal moves per node)
    //std::array<unsigned char,42> node_node_moves_count; //number of legal moves per node
    //std::array<unsigned char,6> player_move_count; //number of legal moves per player
};

struct board{
    std::array<std::array<short,42>,6> player_node;
    std::array<std::array<short,42>,2> node;
    std::array<short,6> player_node_count; //number of nodes per player
    const std::array<std::array<short,6>,42> node_node={{
        {1,3,29,100,100,100}, //0
        {0,2,3,4,100,100},
        {1,4,5,19,100,100},
        {0,1,4,6,100,100},
        {1,2,3,5,6,7}, //4
        {2,4,7,100,100,100},
        {3,4,7,8,100,100},
        {4,5,6,8,100,100},
        {6,7,9,100,100,100},
        {8,10,11,100,100,100}, //9
        {9,11,12,13,100,100},
        {9,10,12,100,100,100},
        {10,11,100,100,100,100},
        {10,14,15,16,24,25},
        {13,16,25,35,100,100}, //14
        {13,16,17,100,100,100},
        {13,14,15,17,18,35},
        {15,16,18,100,100,100},
        {16,17,100,100,100,100},
        {2,20,21,100,100,100}, //19
        {19,21,22,23,100,100},
        {19,20,22,24,100,100},
        {20,21,23,24,25,100},
        {20,22,25,26,32,35},
        {21,22,25,13,100,100}, //24
        {22,23,24,13,14,35},
        {23,27,32,33,100,100},
        {26,28,30,33,34,100},
        {27,29,30,100,100,100},
        {0,28,30,31,100,100}, //29
        {27,28,29,31,34,100},
        {29,30,34,100,100,100},
        {23,26,33,35,36,100},
        {26,27,32,34,36,37},
        {27,30,31,33,100,100}, //34
        {14,16,23,25,32,36},
        {32,33,35,37,100,100},
        {33,36,38,100,100,100},
        {37,39,40,100,100,100},
        {38,40,41,100,100,100}, //39
        {38,39,41,100,100,100},
        {39,40,100,100,100,100}
    }}; //fix: nodes and their connected nodes
    std::array<short,42> node_node_count; //fix: number of connected nodes per node
    //unsigned char node_node_pos[42][42]; //fix: position of node to node connection in the node_node array
    std::array<std::array<short,7>,42> node_node_moves; //nodes and their connected nodes which allow a move (start node has more than 2 infantry units and end node belongs to another player (legal moves per node)
    std::array<short,42> node_node_moves_count; //number of legal moves per node
    std::array<short,6> player_move_count; //number of legal moves per player
};

void init_board(board &board);
void set_random_sequence(std::array<std::array<short,6>,3000> &random_sequence);
short win(float random, short dice);
void set_node_random(board &board, short player);
void update_legal_moves(short from_node,short to_node);
void update_legal_moves(board &board, short from_node,short to_node,short &rand_count, std::array<std::array<short,6>,3000> &random_sequence);
short random_move(short player,board &board);
