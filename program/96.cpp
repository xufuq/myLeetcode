#include <vector>
#include <algorithm>
using namespace std;

// 这个应该是一维数组
// 比如n=5
// 以1为节点 就是前0个后四个组合
// 以2为节点 就是前一个组合与后三个组合的乘积
// ....以此类推
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] =1, dp[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j)
            dp[i] += dp[j]*dp[i-j];
    }
    return dp[n];
}