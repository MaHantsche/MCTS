//
//  functions.cpp
//  MCTS
//
//  Created by Marcel Hantsche on 11.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#include "functions.hpp"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <random>


void init_board(board &board){
    board.player_node_count.fill(0);
    board.player_move_count.fill(0);
    board.node_node_count.fill(0);
    board.node_node_moves_count.fill(0);
    
    //initialise node_node_count
    for (short i=0;i<42;i++){
        short j=0;
        while (board.node_node[i][j]!=100 && j<6){
            j++;
        }
        board.node_node_count[i]=j;
    }
    
    //test if node_node is consistent
    //initalize node_node_pos
    for (short i=0;i<42;i++){
        for (short j=0;j<board.node_node_count[i];j++){
            //sb.node_node_pos[i][sb.node_node[i][j]]=j;
            bool ex=true;
            for (short k=0;k<=board.node_node_count[board.node_node[i][j]];k++){
                if (board.node_node[board.node_node[i][j]][k]==i){
                    ex=false;
                }
            }
            if (ex){
                std::cout << "Error in node " << i << " " << j << " " << board.node_node[i][j] << std::endl;
            }
        }
    }
}

void set_random_sequence(std::array<std::array<short,6>,3000> &random_sequence){
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(0, 1);
    
    //for (unsigned char i=0;i<100;i++){
    //    std::cout << dist(e2) << std::endl;
    //}
    
    for (short i=0;i<3000;i++){
        float rand=dist(e2);
        for (short j=0;j<6;j++){
            random_sequence[i][j]=win(rand,j);
        }
        /*if (i==0){
         std::cout << rand << " " << random_sequence[0][0] << " " << random_sequence[0][1] << " " << random_sequence[0][2] << " " << random_sequence[0][3] << " " << random_sequence[0][4] << " " << random_sequence[0][5] << std::endl;
         }*/
    }
}

short win(float random, short dice){
    //from*2+to-2
    switch (dice) {
        case 1: //1:1
            if (random<0.416667){
                return 0;
            } else {
                return 1;
            }
            break;
        case 2: //1:2
            if (random<0.25463){
                return 0;
            } else {
                return 1;
            }
            break;
        case 3: //2:1
            if (random<0.578704){
                return 0;
            } else {
                return 1;
            }
            break;
        case 4: //2:2
            if (random<0.119599){
                return 0;
            } else {
                if (random<0.767747){
                    return 1;
                } else {
                    return 2;
                }
            }
            break;
        case 5: //3:1
            if (random<0.659722){
                return 0;
            } else {
                return 1;
            }
            break;
        case 6: //3:2
            if (random<0.225823){
                return 0;
            } else {
                if (random<0.847865){
                    return 1;
                } else {
                    return 2;
                }
            }
            break;
        default:
            break;
    }
    return -1;
}

void set_node_random(board &board, short player){
    std::array<short,42> random_array;
    for (short i=0;i<42;i++){
        random_array[i]=i;
    }
    
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(random_array), std::end(random_array),g);
    
    std::cout << std::endl << int(std::time(0)) << " " << random_array[0] << std::endl;

    for (short i=0;i<42;i++){
        board.node[0][random_array[i]]=i%player;
        board.node[1][random_array[i]]=1;
        board.player_node[i%player][board.player_node_count[i%player]]=random_array[i];
        board.player_node_count[i%player]++;
    }

    short infantry=50-player*5;
    short total_infantry=infantry*player;

    for (short i=42;i<total_infantry;i++){
        short r=rand()%board.player_node_count[i%player];
        board.node[1][board.player_node[i%player][r]]++;
    }

    for (short p=0;p<player;p++){
        for (short p_n_c=0;p_n_c<board.player_node_count[p%player];p_n_c++){
            short node_from=board.player_node[p][p_n_c];
            if (board.node[1][node_from]>2){
                for (short n_n_c=0;n_n_c<board.node_node_count[node_from];n_n_c++){
                    short node_to=board.node_node[node_from][n_n_c];
                    if(board.node[0][node_to]!=p){
                        board.node_node_moves[node_from][board.node_node_moves_count[node_from]]=node_to;
                        board.node_node_moves_count[node_from]++;
                        board.player_move_count[p]++;
                    }
                }
            }
        }
    }
}

void update_legal_moves(board &board, short from_node,short to_node,short &rand_count, std::array<std::array<short,6>,3000> &random_sequence){
    short from_inf=board.node[1][from_node];
    short to_inf=board.node[1][to_node];

    short from_node_inf=std::max(3,from_inf-1);
    short to_node_inf=std::max(2,to_inf+0);
    short result=random_sequence[rand_count][from_node_inf*2+to_node_inf-2];
    from_inf=from_inf-result;
    to_inf=to_inf-(std::min(from_node_inf,to_node_inf)-result);
    if (to_inf==0){ //conquer country
        board.node[0][to_node]=board.node[0][from_node];
        board.node[1][to_node]=from_node_inf-result+std::max(2,from_inf-from_node_inf-2);
        board.node[0][from_node]=from_inf - board.node[1][to_node] - result;
        for (int i=0;i<board.node_node_count[to_node];i++){
            if (board.node[0][board.node_node[to_node][i]]==board.node[0][to_node]){
                //b->node_node_moves[][]
            }

        }


    } else {
        if (result==0){ // attack again
            board.node[1][to_node]=to_inf;
            //update_legal_moves(from_node,to_node);
        }
    }

}

