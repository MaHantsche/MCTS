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
        while (node_node[i][j]!=-1){
            j++;
        }
        node_node_count[i]=j-1;
    }
    
    //test if node_node is consistent
    //initalize node_node_pos
    for (int i=0;i<42;i++){
        for (int j=0;j<node_node_count[i];j++){
            node_node_pos[i][node_node[i][j]]=j;
            int k=0;
            bool ex=true;
            while (node_node[node_node[i][j]][k]!=i){
                k++;
                ex=false;
            }
            if (ex){
                std::cout << "Error in node " << i << " " << j << std::endl;
            }
        }
    }
    
    /*
    // random initialisation
    int i=0;
    do {
        int a=rand()%42;
        int b=rand()%42;
        if (a!=b) {
            bool ex=false;
            for (int j=0;j<node_node_count[a];j++){
                if (node_node[a][j]==b){
                    ex=true;
                }
            }
            if (!ex) {
                node_node[a][node_node_count[a]]=b;
                node_node_pos[a][b]=node_node_count[a];
                node_node_count[a]++;
                node_node[b][node_node_count[b]]=a;
                node_node_pos[b][a]=node_node_count[b];
                node_node_count[b]++;
                i++;
                
            }
        }
        
    } while (i<75);
    */
    
}
