#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for(int i=m-2; i>=0;--i) {
        for(int j=n-2;j>=0;--j) {
            dp[i][j] = dp[i][j+1]+dp[i+1][j];
        }
    }
    return dp[0][0];
}