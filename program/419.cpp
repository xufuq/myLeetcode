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
#include <numeric>
using namespace std;


// 依次查看每一行
int countBattleships(vector<vector<char>>& board) {
    int rows = board.size(), cols = board[0].size();
    int count=0;
    // 先对第一行分析
    if(board[0][0]=='X') ++count;
    for(int j = 1; j < cols; j++) {
        if(board[0][j]=='X' && board[0][j-1]=='.') ++count;
    }
    for(int i = 1; i < rows; i++) {
        // 针对这一行分析
        if(board[i][0]=='X' && board[i-1][0]=='.') ++count;
        for(int j = 1; j < cols; j++) {
            if(board[i][j]=='X' && board[i][j-1]=='.' && board[i-1][j]=='.') ++count;
        }
    }
    return count;
}