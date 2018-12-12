//
//  board.cpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

//#include "board.hpp"
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <chrono>
//#include <algorithm>

//board::board(){
//    for (unsigned char i=0;i<6;i++){
//        player_node_count[i]=0;
//        player_move_count[i]=1;
//    }
//
//    for (unsigned char i=0;i<42;i++){
//        node_node_moves_count[i]=0;
//    }
//
//    //initialise node_node_count
//    for (unsigned char i=0;i<42;i++){
//        unsigned char j=0;
//        while (node_node[i][j]!=100 && j<6){
//            j++;
//        }
//        node_node_count[i]=j;
//    }
//
//    //test if node_node is consistent
//    //initalize node_node_pos
//    for (unsigned char i=0;i<42;i++){
//        for (unsigned char j=0;j<node_node_count[i];j++){
//            node_node_pos[i][node_node[i][j]]=j;
//            bool ex=true;
//            for (unsigned char k=0;k<=node_node_count[node_node[i][j]];k++){
//                if (node_node[node_node[i][j]][k]==i){
//                    ex=false;
//                }
//            }
//            if (ex){
//                std::cout << "Error in node " << i << " " << j << " " << node_node[i][j] << std::endl;
//            }
//        }
//    }
//}
//
//void board::get_moves_count(){
//    for (unsigned char i=0;i<42;i++){
//        std::cout << i << " " << node_node_moves_count[i] << std::endl;
//    }
//}
//
//void board::get_player_moves_count(){
//    for (unsigned char i=0;i<6;i++){
//        std::cout << i << " " << player_move_count[i] << std::endl;
//    }
//}
//
//void board::get_nodes(){
//    for (unsigned char i=0;i<42;i++){
//        std::cout << i << " " << node[i][0] << " " << node[i][1] << std::endl;
//    }
//}
//


//unsigned char** board::legal_moves(unsigned char player){
//    unsigned char moves[6][100];
//    for (unsigned char p=0;p<player;p++){
//        for (unsigned char p_n_c=0;p_n_c<player_node_count[p];p_n_c++){
//            unsigned char node_from=player_node[p][p_n_c];
//            for (unsigned char n_n_c=0;n_n_c<node_node_moves_count[node_from];n_n_c++){
//                moves[p][node_from]=node_node_moves[node_from][n_n_c];
//            }
//        }
//    }
//    unsigned char *m=&moves[0][0];
//    return m;
//}
