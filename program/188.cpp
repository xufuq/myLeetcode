#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 怎么将其限制为两笔交易
int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len==0) return 0;
    // dp[len-1][2*k]可以保证最大的原因就是dp[0][2*i]都初始化为-prices[0]
    // 相当于一开始数组都是买入一次的收益和损失
    // 后边随着迭代才慢慢累积次数的
    vector<vector<int>> dp(len, vector<int>(2*k+1, 0));
    for(int i = 1; i < 2*k+1;i+=2)
        dp[0][i]=-prices[0];

    for(int i = 1; i < len;++i) {
        for(int j = 0; j < k;j++) {
            dp[i][2*j+1] = max(dp[i-1][2*j+1], dp[i-1][2*j]-prices[i]);
            dp[i][2*j+2] = max(dp[i-1][2*j+2], dp[i-1][2*j+1]+prices[i]);
        }
    }
    return dp[len-1][2*k];
}   