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
using namespace std;

int getCountAlive(vector<vector<int>>& board, int row, int col) {
    int count = 0;
    if(row-1>=0 && col-1>=0 && abs(board[row-1][col-1])==1) ++count;
    if(row>=0 && col-1>=0 && abs(board[row][col-1])==1) ++count;
    if(row+1<board.size() && col-1>=0 && abs(board[row+1][col-1])==1) ++count;
    if(row+1<board.size() && col>=0 && abs(board[row+1][col])==1) ++count;
    if(row+1<board.size() && col+1<board[0].size() && abs(board[row+1][col+1])==1) ++count;
    if(row<board.size() && col+1<board[0].size() && abs(board[row][col+1])==1) ++count;
    if(row-1>=0 && col+1<board[0].size() && abs(board[row-1][col+1])==1) ++count;
    if(row-1>=0 && col<board[0].size() && abs(board[row-1][col])==1) ++count;
    return count;
}

void gameOfLife(vector<vector<int>>& board) {
    for(int i=0;i<board.size();++i) {
        for(int j=0;j<board[0].size();++j) {
            int count=getCountAlive(board, i, j);
            if(board[i][j]==0) { // 过去是死的，判断现在
                if(count==3) board[i][j]=2;
                else board[i][j]=-2;
            }
            else { // 过去是活的，判断现在
                if(count==2 || count==3)
                    board[i][j]=1;
                else
                    board[i][j]=-1;
            }
        }
    }
    for(int i=0;i<board.size();++i) {
        for(int j=0;j<board[0].size();++j) {
            if(board[i][j]>0) board[i][j]=1;
            else board[i][j]=0;
        }
    }
}