#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    // dp存的是当前点能够使用的最大正方形边长
    // 关键是这个正方形边长的递推关系的推导很重要
    vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
    int result=0;
    for(int row = 1; row <= rows; ++row){
        for(int col = 1; col <= cols; ++col){
            if(matrix[row-1][col-1])
                dp[row][col]=min(min(dp[row-1][col], dp[row-1][col-1]), dp[row][col-1])+1;
            result+=dp[row][col];
        }
    }
    return result;
}