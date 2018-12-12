//
//  ai.cpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

//#include "ai.hpp"
//#include <cstdlib>
//#include <algorithm>
//#include <iostream>
//#include <random>
//#include <math.h>
//
//void ai::initailize_board_random(board &b, unsigned char player){
//    unsigned char random_array[42];
//    for (unsigned char i=0;i<42;i++){
//        random_array[i]=i;
//    }
//    
//    std::random_shuffle(std::begin(random_array), std::end(random_array));
//    
//    for (unsigned char i=0;i<42;i++){
//        b.node[random_array[i]][0]=i%player;
//        b.node[random_array[i]][1]=1;
//        b.player_node[i%player][b.player_node_count[i%player]]=random_array[i];
//        b.player_node_count[i%player]++;
//    }
//    
//    unsigned char infantry=50-player*5;
//    unsigned char total_infantry=infantry*player;
//    
//    for (unsigned char i=42;i<total_infantry;i++){
//        unsigned char r=rand()%b.player_node_count[i%player];
//        b.node[b.player_node[i%player][r]][1]++;
//    }
//    
//    for (unsigned char p=0;p<player;p++){
//        for (unsigned char p_n_c=0;p_n_c<b.player_node_count[p%player];p_n_c++){
//            unsigned char node_from=b.player_node[p][p_n_c];
//            if (b.node[node_from][1]>2){
//                for (unsigned char n_n_c=0;n_n_c<b.node_node_count[node_from];n_n_c++){
//                    unsigned char node_to=b.node_node[node_from][n_n_c];
//                    if(b.node[node_to][0]!=p){
//                        b.node_node_moves[node_from][b.node_node_moves_count[node_from]]=node_to;
//                        b.node_node_moves_count[node_from]++;
//                        b.player_move_count[p]++;
//                    }
//                }
//            }
//        }
//    }
//    this->b=new board(b);
//}
//
//void ai::set_random_sequence(){
//    std::random_device rd;
//    std::mt19937 e2(rd());
//    std::uniform_real_distribution<> dist(0, 1);
//    
//    //for (unsigned char i=0;i<100;i++){
//    //    std::cout << dist(e2) << std::endl;
//    //}
//    
//    for (short int i=0;i<3000;i++){
//        float rand=dist(e2);
//        for (unsigned char j=0;j<6;j++){
//            random_seq[i][j]=win(rand,j);
//        }
//        /*if (i==0){
//            std::cout << rand << " " << random_seq[0][0] << " " << random_seq[0][1] << " " << random_seq[0][2] << " " << random_seq[0][3] << " " << random_seq[0][4] << " " << random_seq[0][5] << std::endl;
//        }*/
//    }
//}
//
//unsigned char ai::win(double random, unsigned char dice){
//    switch (dice) {
//        case 1: //1:1
//            if (random<0.416667){
//                return 0;
//            } else {
//                return 1;
//            }
//            break;
//        case 2: //1:2
//            if (random<0.25463){
//                return 0;
//            } else {
//                return 1;
//            }
//            break;
//        case 3: //2:1
//            if (random<0.578704){
//                return 0;
//            } else {
//                return 1;
//            }
//            break;
//        case 4: //2:2
//            if (random<0.119599){
//                return 0;
//            } else {
//                if (random<0.767747){
//                    return 1;
//                } else {
//                    return 2;
//                }
//            }
//            break;
//        case 5: //3:1
//            if (random<0.659722){
//                return 0;
//            } else {
//                return 1;
//            }
//            break;
//        case 6: //3:2
//            if (random<0.225823){
//                return 0;
//            } else {
//                if (random<0.847865){
//                    return 1;
//                } else {
//                    return 2;
//                }
//            }
//            break;
//        default:
//            break;
//    }
//    return -1;
//}
//
//void ai::get_chances(){
//    unsigned char dices[3][2][3];
//    for (unsigned char i=0;i<3;i++){
//        for (unsigned char j=0;j<2;j++){
//            for (unsigned char k=0;k<3;k++){
//                dices[i][j][k]=0;
//            }
//        }
//    }
//    
//    for (unsigned char i=1;i<=6;i++){
//        for (unsigned char j=1;j<=6;j++){
//            for (unsigned char k=1;k<=6;k++){
//                for (unsigned char l=1;l<=6;l++){
//                    for (unsigned char m=1;m<=6;m++){
//                        if (i>j){
//                            dices[0][0][0]++;
//                        } else {
//                            dices[0][0][1]++;
//                        }
//                        if(std::max(i,j)>k){
//                            dices[1][0][0]++;
//                        } else {
//                            dices[1][0][1]++;
//                        }
//                        if(std::max(std::max(i,j),k)>l){
//                            dices[2][0][0]++;
//                        } else {
//                            dices[2][0][1]++;
//                        }
//                        if(i>std::max(k,l)){
//                            dices[0][1][0]++;
//                        } else {
//                            dices[0][1][1]++;
//                        }
//                        if(std::min(i,j)>std::max(k,l)){
//                            dices[1][1][0]++;
//                        } else {
//                            if (std::max(i,j)<=std::min(k,l)){
//                                dices[1][1][2]++;
//                            } else {
//                                dices[1][1][1]++;
//                            }
//                        }
//                        unsigned char a,b;
//                        if (i<j){
//                            a=j;
//                            if (k>i){
//                                b=k;
//                            } else {
//                                b=i;
//                            }
//                        } else {
//                            a=i;
//                            if (k>j){
//                                b=k;
//                            } else {
//                                b=j;
//                            }
//                        }
//                        if(std::min(a,b)>std::max(l,m)){
//                            dices[2][1][0]++;
//                        } else {
//                            if (std::max(a,b)<=std::min(l,m)){
//                                dices[2][1][2]++;
//                            } else {
//                                dices[2][1][1]++;
//                            }
//                        }
//                        
//                    }
//                }
//            }
//        }
//    }
//    unsigned char sum=0;
//    for (unsigned char i=0;i<3;i++){
//        for (unsigned char j=0;j<2;j++){
//            sum=0;
//            for (unsigned char k=0;k<3;k++){
//                sum+=dices[i][j][k];
//            }
//            std::cout << i << " " << j << " " << float(dices[i][j][0])/float(sum) << " " << float(dices[i][j][0]+dices[i][j][1])/float(sum) << std::endl;
//        }
//    }
//}
//
//void ai::update_legal_moves(unsigned char from_node,unsigned char to_node){
//    unsigned char from_inf=b->node[from_node][1];
//    unsigned char to_inf=b->node[to_node][1];
//    
//    unsigned char from_node_inf=std::max(3,from_inf-1);
//    unsigned char to_node_inf=std::max(2,to_inf+0);
//    unsigned char result=random_seq[rand_count][from_node_inf*3+to_node_inf-4];
//    from_inf=from_inf-result;
//    to_inf=to_inf-(std::min(from_node_inf,to_node_inf)-result);
//    if (to_inf==0){ //conquer country
//        b->node[to_node][0]=b->node[from_node][0];
//        b->node[to_node][1]=from_node_inf-result+std::max(2,from_inf-from_node_inf-2);
//        for (int i=0;i<b->node_node_count[to_node];i++){
//            if (b->node[b->node_node[to_node][i]][0]==b->node[to_node][0]){
//                //b->node_node_moves[][]
//            }
//            
//        }
//        
//        
//    } else {
//        if (result==0){ // attack again
//            b->node[to_node][1]=to_inf;
//            update_legal_moves(from_node,to_node);
//        }
//    }
//    
//}
