#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    // 动态规划一维数组解决
    int n=grid[0].size();
    vector<int> dp(n);
    dp[0] = grid[0][0];
    for(int i=1;i<n;++i) 
        dp[i]=dp[i-1] + grid[0][i];
    for(auto n : dp)
        cout << n << " ";
    cout << endl;
    for(int i=1;i<n;++i){
        dp[0]=dp[0]+ grid[i][0];
        for(int j=1;j<n;++j) 
            dp[j] = min(dp[j-1], dp[j])+grid[i][j];
        for(auto n : dp)
            cout << n << " ";
        cout << endl;
    }
    return dp[n-1];
}

int main(){
    vector<vector<int>> grid={{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
}