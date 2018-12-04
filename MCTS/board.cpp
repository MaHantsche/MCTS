//
//  board.cpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#include "board.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

board::board(){
    for (int i=0;i<6;i++){
        player_node_count[i]=0;
        player_move_count[i]=1;
    }
    
    for (int i=0;i<42;i++){
        node_node_moves_count[i]=0;
    }
    
    //initialise node_node_count
    for (int i=0;i<42;i++){
        int j=0;
        while (node_node[i][j]!=-1 && j<6){
            j++;
        }
        node_node_count[i]=j;
    }
    
    //test if node_node is consistent
    //initalize node_node_pos
    for (int i=0;i<42;i++){
        for (int j=0;j<node_node_count[i];j++){
            node_node_pos[i][node_node[i][j]]=j;
            bool ex=true;
            for (int k=0;k<=node_node_count[node_node[i][j]];k++){
                if (node_node[node_node[i][j]][k]==i){
                    ex=false;
                }
            }
            if (ex){
                std::cout << "Error in node " << i << " " << j << " " << node_node[i][j] << std::endl;
            }
        }
    }
}

void board::get_moves_count(){
    for (int i=0;i<42;i++){
        std::cout << i << " " << node_node_moves_count[i] << std::endl;
    }
}

void board::get_player_moves_count(){
    for (int i=0;i<6;i++){
        std::cout << i << " " << player_move_count[i] << std::endl;
    }
}

void board::get_nodes(){
    for (int i=0;i<42;i++){
        std::cout << i << " " << node[i][0] << " " << node[i][1] << std::endl;
    }
}

//int** board::legal_moves(int player){
//    int moves[6][100];
//    for (int p=0;p<player;p++){
//        for (int p_n_c=0;p_n_c<player_node_count[p];p_n_c++){
//            int node_from=player_node[p][p_n_c];
//            for (int n_n_c=0;n_n_c<node_node_moves_count[node_from];n_n_c++){
//                moves[p][node_from]=node_node_moves[node_from][n_n_c];
//            }
//        }
//    }
//    int *m=&moves[0][0];
//    return m;
//}
