#include <iostream>
#include <vector>
using namespace std;


// 时间复杂度过高
// 用数组+动态规划做,这里需要添加一个记忆优化组
// int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
//     if(maxMove < 1) return 0; // 不能再移动
//     // if(dp.empty()) dp=vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove,-1)));
//     int totalPaths = 0;
//     if(startRow==0 )      ++totalPaths;
//     else                  totalPaths += findPaths(m, n, maxMove-1, startRow-1, startColumn);
//     if(startRow==m-1)     ++totalPaths;
//     else                  totalPaths += findPaths(m, n, maxMove-1, startRow+1, startColumn);
//     if(startColumn==0)    ++totalPaths;
//     else                  totalPaths += findPaths(m, n, maxMove-1, startRow, startColumn-1);
//     if(startColumn==n-1)  ++totalPaths;
//     else                  totalPaths += findPaths(m, n, maxMove-1, startRow, startColumn+1);
//     // dp[startRow][startColumn][maxMove]=totalPaths%1000000007;
//     return totalPaths%1000000007;
// }

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    if(maxMove == 0) return 0; // 不能再移动
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1,0))); // 行，列，步数
    for(int i=1;i<=maxMove;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                if(j==0)   ++dp[j][k][i];
                else       dp[j][k][i] += dp[j-1][k][i-1]; // 一步上移
                if(j==m-1) ++dp[j][k][i];
                else       dp[j][k][i] += dp[j+1][k][i-1]; // 一步下移
                if(k==0)   ++dp[j][k][i];
                else       dp[j][k][i] += dp[j][k-1][i-1]; // 一步左移
                if(k==n-1) ++dp[j][k][i];
                else       dp[j][k][i] += dp[j][k+1][i-1]; // 一步左移
            }
        }
    }
    return dp[startRow][startColumn][maxMove]%1000000007;
}

int main(){
    cout << findPaths(1,3,3,0,1) << endl;
    // cout << findPaths(2,2,2,0,0) << endl;
}