#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "math.h"
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> RCused(2, vector<int>(9, 0)); // RCused[0] 是各行都有那个数，RCused[1]是各列都要那个数
    vector<vector<int>> RectUsed(3, vector<int>(3, 0));
    for(int row = 0; row < 9;++row) {
        for(int col = 0; col < 9;++col) {
            if(board[row][col]!='.'){
                int num=board[row][col]-'0';
                if((RCused[0][row]>>num & 1) || (RCused[1][col]>>num & 1) || RectUsed[row/3][col/3]>>num & 1) return false;
                else {
                    RCused[0][row] |= 1 << num;
                    RCused[1][col] |= 1 << num;
                    RectUsed[row/3][col/3] |= 1 << num;
                }
            }
        }
    }
    return true;
}