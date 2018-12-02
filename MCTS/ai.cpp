//
//  ai.cpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#include "ai.hpp"
#include <cstdlib>
#include <algorithm>

void ai::initailize_board_random(board &b, int player){
    int random_array[42];
    for (int i=0;i<42;i++){
        random_array[i]=i;
    }
    
    std::random_shuffle(std::begin(random_array), std::end(random_array));
    
    for (int i=0;i<42;i++){
        b.node[random_array[i]][0]=i%player;
        b.node[random_array[i]][1]=1;
        b.player_node[i%player][b.player_node_count[i%player]]=random_array[i];
        b.player_node_count[i%player]++;
    }
    
    int infantry=50-player*5;
    int total_infantry=infantry*player;
    
    for (int i=42;i<total_infantry;i++){
        int r=rand()%b.player_node_count[i%player];
        b.node[b.player_node[i%player][r]][1]++;
    }
    
    for (int p=0;p<player;p++){
        for (int node_from=0;node_from<b.player_node_count[p%player];node_from++){
            if (b.node[node_from][1]>2){
                for (int node_to=0;node_to<b.node_node_count[b.player_node[p][node_from]];node_to++){
                    if(b.node[node_to][0]!=p){
                        b.node_node_moves[node_from][b.node_node_moves_count[node_from]]=node_to;
                        b.node_node_moves_count[node_from]++;
                    }
                }
            }
        }
    }
}

void ai::set_random_sequence(){
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            this->random_seq[i][j]=random();
        }
    }
    
}