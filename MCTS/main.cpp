//
//  main.cpp
//  MCTS
//
//  Created by Marcel Hantsche on 01.12.18.
//  Copyright © 2018 Marcel Hantsche. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "board.hpp"
#include "ai.hpp"

using namespace std;
using namespace std::chrono;


int main(int argc, const char * argv[]) {
    // insert code here...
    int r1,r2;
    srand(int(time(NULL)));
    
    int node[42][2];
    for (int i=0;i<42;i++){
        node[i][0]=rand()%6;
        node[i][1]=rand()%4+1;
    }
    
    int edge[166][6];
    int node2[42][42];
    int node2_counter[42];
    int player2[6][42];
    int player2_counter[6];
    
    for (int i=0;i<42;i++){
        node2_counter[i]=0;
    }
    
    for (int i=0;i<6;i++){
        player2_counter[i]=0;
    }

    for (int i=0;i<166;i++){
        r1=rand()%42;
        r2=rand()%42;
        //if (r1!=r2){
            edge[i][0]=r1; //node from
            edge[i][1]=r2; //node to
            edge[i][2]=node[r1][0]; //player from
            edge[i][3]=node[r2][0]; //player to
            edge[i][4]=node[r1][1]; //infantry from
            edge[i][5]=node[r2][1]; //infantry to
            node2[r1][node2_counter[r1]]=i;
            node2_counter[r1]++;
            player2[node[r1][0]][player2_counter[node[r1][0]]]=i;
            player2_counter[node[r1][0]]++;
        
        //}
    }
    
    
    int player=0;
    
    int counter=0;
    int lookup[166];
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i=0;i<166;i++){
        if ((edge[i][2]==player) && (edge[i][3]!=player) && (edge[i][4]>2) && (2*edge[i][4]>edge[i][5])){
            lookup[counter]=i;
            counter+=1;
        }
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    auto duration = duration_cast<nanoseconds>( t2 - t1 ).count();
    
    cout << duration << " " << counter << "\n";
    
    int j;
    
    counter=0;
    t1 = high_resolution_clock::now();
    for (int i=0;i<=player2_counter[player];i++){
        j=player2[player][i];
        if ((edge[j][4]>2) && (edge[j][3]!=player) && (2*edge[j][4]>edge[j][5])){
            lookup[counter]=j;
            counter+=1;
        }
        //cout << i << "\n";
    }
    t2 = high_resolution_clock::now();
    
    duration = duration_cast<nanoseconds>( t2 - t1 ).count();
    
    cout << duration << " " << counter << "\n";
    
    int pl_no[6][42];
    int pl_no_co[6];
    int no[42][3];
    int no_no[42][7];
    int no_no_co[42];
    int no_no_[42][7];
    int no_no_co_[42];
    int pl_move[6];
    
    for (int i=0;i<6;i++){
        pl_no_co[i]=0;
        pl_move[i]=1;
    }
    
    for (int i=0;i<42;i++){
        no_no_co[i]=0;
        no_no_co_[i]=0;
    }
    
    bool ex;
    
    for (int i=0;i<166;i++){
        ex=true;
        for (int j=0;j<=pl_no_co[edge[i][2]];j++){
            if (pl_no[edge[i][2]][j]==edge[i][0]){
                ex=false;
            }
        }
        if (ex){
            pl_no[edge[i][2]][pl_no_co[edge[i][2]]]=edge[i][0];
            pl_no_co[edge[i][2]]++;
        }
        
        no[edge[i][0]][0]=edge[i][2];
        no[edge[i][0]][1]=edge[i][4];
        if (edge[i][0]!=edge[i][1]){
            no_no[edge[i][0]][no_no_co[edge[i][0]]]=edge[i][1];
            no_no_co[edge[i][0]]++;
            if ((edge[i][0]>2) && (edge[i][2]!=edge[i][3])){
                no_no_[edge[i][0]][no_no_co_[edge[i][0]]]=edge[i][1];
                no_no_co_[edge[i][0]]++;
                pl_move[edge[i][2]]++;
            }
        }
    }
    
    t1 = high_resolution_clock::now();
    
    // choose move
    int m=rand()%pl_move[0];
    if (m+1==pl_move[0]){
        //no move
    } else {
        int sum=0;
        int i=0;
        while (sum<m){
            sum+=no_no_co_[pl_no[0][i]];
            i++;
        }
        i--;
        int inf_to=no_no_[pl_no[0][i]][m-1-sum+no_no_co_[pl_no[0][i]]];
    }
    
    
    
    t2 = high_resolution_clock::now();
    
    duration = duration_cast<nanoseconds>( t2 - t1 ).count();
    
    cout << duration << " " << pl_move[0] << "\n";
    

    board b=board();
    
    
    
    //std::cout << "Hello, World!\n";
    return 0;
}

// update moves
void update_moves(int a, int b){
    
}



