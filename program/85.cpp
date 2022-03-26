#include <vector>
#include <algorithm>
using namespace std;

// 最大矩形，动态规划
// 计算当前点参与的不同的矩形，分别计算面积
int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int maxSize=0, curSize=0;
    vector<vector<int>> dp(rows+1, vector<int>(cols+1, 0));
    for(int row = 1; row < rows; ++row) {
        for(int col = 1; col < cols; ++col){
            if(matrix[row-1][col-1]) {
                dp[row][col] = dp[row][col-1]+1;
                int minWidth=INT_MAX;
                for(int i=row;i>0&&dp[i][col];--i){
                    minWidth=min(minWidth, dp[i][col]);
                    curSize=minWidth*(row-i+1);
                    maxSize=max(maxSize, curSize);
                }
            }
        }
    }
    return maxSize;
}

// 官方题解是先按照相同方法获得dp
// 然后用84题柱状图单调栈的方法，逐列判断最大值