#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// 挖到雷返回false，直接返回当前表格
bool digOut(vector<vector<char>>& board, vector<int>& click) {
    int x=click[0], y=click[1];
    if(board[x][y]=='M') {
        board[x][y]='X';
        return false;
    }
    vector<vector<int>> circleIndex;
    int count=0;
    if(x-1>=0 && y-1>=0) {
        if(board[x-1][y-1]=='M') 
            ++count;
        else if(board[x-1][y-1]=='E')
            circleIndex.push_back({x-1, y-1});
    }
    if(x-1>=0) {
        if(board[x-1][y]=='M') 
            ++count;
        else if(board[x-1][y]=='E')
            circleIndex.push_back({x-1, y});
    }
    if(y-1>=0) {
        if(board[x][y-1]=='M') 
            ++count;
        else if(board[x][y-1]=='E')
            circleIndex.push_back({x, y-1});
    }
    if(x-1>=0 && y+1<board[0].size()) {
        if(board[x-1][y+1]=='M') 
            ++count; 
        else if(board[x-1][y+1]=='E')
            circleIndex.push_back({x-1, y+1});
    }
    if(x+1<board.size() && y-1>=0) {
        if(board[x+1][y-1]=='M') 
            ++count;
        else if(board[x+1][y-1]=='E')
            circleIndex.push_back({x+1, y-1});
    }
    if(x+1<board.size()) {
        if(board[x+1][y]=='M') 
            ++count;
        else if(board[x+1][y]=='E')
            circleIndex.push_back({x+1, y});
    }
    if(y+1<board[0].size()) {
        if(board[x][y+1]=='M') 
            ++count;
        else if(board[x][y+1]=='E')
            circleIndex.push_back({x, y+1});
    }
    if(x+1<board.size() && y+1<board[0].size()) {
        if(board[x+1][y+1]=='M') 
            ++count;
        else if(board[x+1][y+1]=='E')
            circleIndex.push_back({x+1, y+1});
    }

    if(count==0) {
        board[x][y] = 'B';
        for(auto &vec:circleIndex)
            digOut(board, vec);
    }
    else
        board[x][y] = '0'+count;
    return true;
}

// 用队列实现递归显示，这样的话减少空间和时间复杂度
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    digOut(board, click);
    return board;
}