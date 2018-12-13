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
//#include "board.hpp"
//#include "ai.hpp"
#include "functions.hpp"

using namespace std;
using namespace std::chrono;

//void old_code();

int main(int argc, const char * argv[]) {
    // insert code here...
    srand(int(time(0)));
    short rand_count=0;
    
    std::array<std::array<short,6>,3000> rand_sequence;
    board b;
    init_board(b);
    set_random_sequence(rand_sequence);
    short player=6;
    set_node_random(b, player);
    
    short move=random_move(0,b);
    update_legal_moves(b,move / 100,move % 100,rand_count, rand_sequence);
    
    //fortify(0);
    
    //get_infantry(0);
    
    
    
    cout << b.node.size() << endl;
    cout << b.node[0].size() << endl;
    cout << b.node_node[0].size() << endl;
    
    //for (int i=0;i<42;i++){
    //    std::cout << i << " " << b.node[0][i] << " " << b.node[1][i] << std::endl;
    //}
    
    
    
    
    //old_code();
    
    cout << "Hello, World!\n";
    //return 0;
}
    
    
    
void old_code(){
    
    unsigned char r1,r2;
    srand(int(time(NULL)));

    unsigned char node[42][2];
    for (unsigned char i=0;i<42;i++){
        node[i][0]=rand()%6;
        node[i][1]=rand()%4+1;
    }
    
    unsigned char edge[166][6];
    unsigned char node2[42][42];
    unsigned char node2_counter[42];
    unsigned char player2[6][42];
    unsigned char player2_counter[6];

    for (unsigned char i=0;i<42;i++){
        node2_counter[i]=0;
    }

    for (unsigned char i=0;i<6;i++){
        player2_counter[i]=0;
    }

    for (unsigned char i=0;i<166;i++){
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
    

    unsigned char player=0;

    unsigned char counter=0;
    unsigned char lookup[166];

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (unsigned char i=0;i<166;i++){
        if ((edge[i][2]==player) && (edge[i][3]!=player) && (edge[i][4]>2) && (2*edge[i][4]>edge[i][5])){
            lookup[counter]=i;
            counter+=1;
        }
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>( t2 - t1 ).count();

    cout << duration << " " << counter << "\n";

    unsigned char j;

    counter=0;
    t1 = high_resolution_clock::now();
    for (unsigned char i=0;i<=player2_counter[player];i++){
        j=player2[player][i];
        /*if ((edge[j][4]>2) && (edge[j][3]!=player) && (2*edge[j][4]>edge[j][5])){
            lookup[counter]=j;
            counter+=1;
        }*/
        //cout << i << "\n";
    }
    t2 = high_resolution_clock::now();

    duration = duration_cast<nanoseconds>( t2 - t1 ).count();

    cout << duration << " " << counter << "\n";

    unsigned char pl_no[6][42];
    unsigned char pl_no_co[6];
    unsigned char no[42][3];
    unsigned char no_no[42][7];
    unsigned char no_no_co[42];
    unsigned char no_no_[42][7];
    unsigned char no_no_co_[42];
    unsigned char pl_move[6];

    for (unsigned char i=0;i<6;i++){
        pl_no_co[i]=0;
        pl_move[i]=1;
    }

    for (unsigned char i=0;i<42;i++){
        no_no_co[i]=0;
        no_no_co_[i]=0;
    }

    bool ex;

    for (unsigned char i=0;i<166;i++){
        ex=true;
        for (unsigned char j=0;j<=pl_no_co[edge[i][2]];j++){
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
    unsigned char m=rand()%pl_move[0];
    if (m+1==pl_move[0]){
        //no move
    } else {
        unsigned char sum=0;
        unsigned char i=0;
        while (sum<m){
            sum+=no_no_co_[pl_no[0][i]];
            i++;
        }
        i--;
        //unsigned char inf_to=no_no_[pl_no[0][i]][m-1-sum+no_no_co_[pl_no[0][i]]];
    }



    t2 = high_resolution_clock::now();

    duration = duration_cast<nanoseconds>( t2 - t1 ).count();

    cout << duration << " " << pl_move[0] << "\n";
    
    
    t1 = high_resolution_clock::now();
    t2 = high_resolution_clock::now();
    
    duration = duration_cast<nanoseconds>( t2 - t1 ).count();
    
    cout << duration << " " << pl_move[0] << "\n";
    
    

}


