#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int maxProfit(vector<int>& prices) {
    // 由于有冷冻期，所以应该今天买入应该访问前2天的收益
    int len = prices.size();
    if(len<2) return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    // [0][0]表示买入，[0][1]表示卖出
    // 这里解决边界问题
    dp[0][0] = -prices[0], dp[0][1] = 0;
    dp[1][0] = max(dp[0][0], -prices[1]), dp[1][1] = max(0, prices[1] - prices[0]);
    for(int i=2; i<len; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-2][1]-prices[i]); // 前两天的收益，前一天冷静期，今天才可以买入
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
    }
    return dp[len-1][1];
}