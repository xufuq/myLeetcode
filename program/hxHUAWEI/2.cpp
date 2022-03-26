#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int getVale(int x, int y, int rows, vector<int> &matrix) {
    return matrix[x*rows + y];
}

int getMinStep(int rows, int cols, vector<int> &matrix){
    if(matrix.empty()) return -1;
    if(matrix[0]==0 || matrix.back()==0) return -1;
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
    dp[0][0]=0; //
    for(int i=0; i<rows; ++i){
        for(int j=0; j<cols; ++j){
            int curMaxStep=getVale(i, j, rows, matrix);
            if(curMaxStep==0) continue;
            int xStart=max(0, i-10), yStart=max(0, j-10);
            for(int x=xStart;x<i;++x) {
                if(getVale(x, j, rows, matrix)>=i-x && dp[i][j]>dp[x][j]+1) 
                    dp[i][j]=dp[x][j]+1;
            }
            for(int y=yStart;y<j;++y) {
                if(getVale(i, y, rows, matrix)>=j-y && dp[i][j]>dp[i][y]+1)
                    dp[i][j]=dp[i][y]+1;
            }
        }
    }
    return dp[rows-1][cols-1]==INT_MAX?-1:dp[rows-1][cols-1];
}

int main() {
    int rows, cols;
    cin >> rows  >> cols;
    int num=rows*cols, count=0;
    vector<int> matrix(num);
    while(count<num) 
        cin >> matrix[count++];
    cout << getMinStep(rows,cols,matrix) << endl;
    return 0;
}