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
        node_node_count[i]=0;
        node_node_moves_count[i]=0;
    }
    /*
     node_node[0][0]=1;
     node_node[0][1]=2;
     node_node[0][2]=3;
     node_node[0][3]=4;
     node_node[0][4]=5;
     node_node[0][5]=6;
     node_node[0][6]=7;
     node_node_count[0]=7;
     
     node_node[1][0]=1;
     node_node[1][1]=2;
     node_node[1][2]=3;
     node_node[1][3]=4;
     node_node[1][4]=5;
     node_node[1][5]=6;
     node_node[1][6]=7;
     node_node_count[1]=7;
     
     node_node[2][0]=1;
     node_node[2][1]=2;
     node_node[2][2]=3;
     node_node[2][3]=4;
     node_node[2][4]=5;
     node_node[2][5]=6;
     node_node[2][6]=7;
     node_node_count[2]=7;
     
     node_node[3][0]=1;
     node_node[3][1]=2;
     node_node[3][2]=3;
     node_node[3][3]=4;
     node_node[3][4]=5;
     node_node[3][5]=6;
     node_node[3][6]=7;
     node_node_count[3]=7;
     
     node_node[4][0]=1;
     node_node[4][1]=2;
     node_node[4][2]=3;
     node_node[4][3]=4;
     node_node[4][4]=5;
     node_node[4][5]=6;
     node_node[4][6]=7;
     node_node_count[4]=7;
     
     node_node[5][0]=1;
     node_node[5][1]=2;
     node_node[5][2]=3;
     node_node[5][3]=4;
     node_node[5][4]=5;
     node_node[5][5]=6;
     node_node[5][6]=7;
     node_node_count[5]=7;
     
     node_node[6][0]=1;
     node_node[6][1]=2;
     node_node[6][2]=3;
     node_node[6][3]=4;
     node_node[6][4]=5;
     node_node[6][5]=6;
     node_node[6][6]=7;
     node_node_count[6]=7;
     
     node_node[7][0]=1;
     node_node[7][1]=2;
     node_node[7][2]=3;
     node_node[7][3]=4;
     node_node[7][4]=5;
     node_node[7][5]=6;
     node_node[7][6]=7;
     node_node_count[7]=7;
     
     node_node[8][0]=1;
     node_node[8][1]=2;
     node_node[8][2]=3;
     node_node[8][3]=4;
     node_node[8][4]=5;
     node_node[8][5]=6;
     node_node[8][6]=7;
     node_node_count[8]=7;
     
     node_node[9][0]=1;
     node_node[9][1]=2;
     node_node[9][2]=3;
     node_node[9][3]=4;
     node_node[9][4]=5;
     node_node[9][5]=6;
     node_node[9][6]=7;
     node_node_count[9]=7;
     
     node_node[10][0]=1;
     node_node[10][1]=2;
     node_node[10][2]=3;
     node_node[10][3]=4;
     node_node[10][4]=5;
     node_node[10][5]=6;
     node_node[10][6]=7;
     node_node_count[10]=7;
     
     node_node[11][0]=1;
     node_node[11][1]=2;
     node_node[11][2]=3;
     node_node[11][3]=4;
     node_node[11][4]=5;
     node_node[11][5]=6;
     node_node[11][6]=7;
     node_node_count[11]=7;
     
     node_node[12][0]=1;
     node_node[12][1]=2;
     node_node[12][2]=3;
     node_node[12][3]=4;
     node_node[12][4]=5;
     node_node[12][5]=6;
     node_node[12][6]=7;
     node_node_count[12]=7;
     
     node_node[13][0]=1;
     node_node[13][1]=2;
     node_node[13][2]=3;
     node_node[13][3]=4;
     node_node[13][4]=5;
     node_node[13][5]=6;
     node_node[13][6]=7;
     node_node_count[13]=7;
     
     node_node[14][0]=1;
     node_node[14][1]=2;
     node_node[14][2]=3;
     node_node[14][3]=4;
     node_node[14][4]=5;
     node_node[14][5]=6;
     node_node[14][6]=7;
     node_node_count[14]=7;
     
     node_node[15][0]=1;
     node_node[15][1]=2;
     node_node[15][2]=3;
     node_node[15][3]=4;
     node_node[15][4]=5;
     node_node[15][5]=6;
     node_node[15][6]=7;
     node_node_count[15]=7;
     
     node_node[16][0]=1;
     node_node[16][1]=2;
     node_node[16][2]=3;
     node_node[16][3]=4;
     node_node[16][4]=5;
     node_node[16][5]=6;
     node_node[16][6]=7;
     node_node_count[16]=7;
     
     node_node[17][0]=1;
     node_node[17][1]=2;
     node_node[17][2]=3;
     node_node[17][3]=4;
     node_node[17][4]=5;
     node_node[17][5]=6;
     node_node[17][6]=7;
     node_node_count[17]=7;
     
     node_node[18][0]=1;
     node_node[18][1]=2;
     node_node[18][2]=3;
     node_node[18][3]=4;
     node_node[18][4]=5;
     node_node[18][5]=6;
     node_node[18][6]=7;
     node_node_count[18]=7;
     
     node_node[19][0]=1;
     node_node[19][1]=2;
     node_node[19][2]=3;
     node_node[19][3]=4;
     node_node[19][4]=5;
     node_node[19][5]=6;
     node_node[19][6]=7;
     node_node_count[19]=7;
     
     node_node[20][0]=1;
     node_node[20][1]=2;
     node_node[20][2]=3;
     node_node[20][3]=4;
     node_node[20][4]=5;
     node_node[20][5]=6;
     node_node[20][6]=7;
     node_node_count[20]=7;
     */
    
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
    
}