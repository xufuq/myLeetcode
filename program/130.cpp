#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

void set1(vector<vector<char>>& board, int row, int col) {
    if(row>0 && board[row-1][col] == 'O'){
        board[row-1][col] = 'M';
        set1(board, row-1, col);
    }
    if(col>0 && board[row][col-1] == 'O'){
        board[row][col-1] = 'M';
        set1(board, row, col-1);
    }
    if(row<board.size()-1 && board[row+1][col] == 'O'){
        board[row+1][col] = 'M';
        set1(board, row+1, col);
    }
    if(col<board[0].size()-1 && board[row][col+1] == 'O'){
        board[row][col+1] = 'M';
        set1(board, row, col+1);
    }
}

// 找到与边界相邻的块，然后再反过来
void solve(vector<vector<char>>& board) {
    int row = board.size(), col = board[0].size();
    for(int i=0;i<col;i++) {
        if(board[0][i]=='O') set1(board, 0, i);
        if(board[row-1][i]=='O') set1(board, row-1, i);
    }
    for(int i=0;i<row;++i){
        if(board[i][0]=='O') set1(board, i, 0);
        if(board[i][col-1]=='O') set1(board,i, col-1);
    }
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='M') board[i][j]='O';
        }
    }
}