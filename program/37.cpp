#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;


int totalLength = 9;

vector<char> getViableNums(vector<vector<char>>& board, int row, int col){
    bool appearNums[10]={false};
    
    for(int i = 0; i < totalLength;++i){ // 添加同一行列
        if(board[i][col]!='.') appearNums[board[i][col]-'0']=true;
        if(board[row][i]!='.') appearNums[board[row][i]-'0']=true;
    }
    int a = row/3, b = col/3;
    for(int i=3*a;i<3*a+3;++i)
        for(int j = 3*b; j < 3*b+3;++j)
            if(board[i][j]!='.') appearNums[board[i][j]-'0']=true;

    vector<char> viableNums;
    for(char i=1;i<=9;++i) // 把可以添加的元素找出来
        if(!appearNums[i])
            viableNums.push_back(i+'0');
    return viableNums;
}

bool solveSudoku(vector<vector<char>>& board, vector<int> &currentBlank, int startIndex) {
    if(startIndex==currentBlank.size()) return true;
    int col = currentBlank[startIndex];
    int row = currentBlank[startIndex+1];
    vector<char> viableNums = getViableNums(board, row, col);
    while(!viableNums.empty()) {
        board[row][col]=viableNums.back();
        viableNums.pop_back();
        if(solveSudoku(board, currentBlank, startIndex+2))
            return true;
    }
    board[row][col]='.';
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    vector<int> currentBlank; // 相邻的两个是 一对 row col
    for(int i=0;i<totalLength; ++i)
        for(int j=0;j<totalLength;++j)
            if(board[i][j]=='.'){
                currentBlank.push_back(i);
                currentBlank.push_back(j);
            }
                
    solveSudoku(board, currentBlank, 0);
}