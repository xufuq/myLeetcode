#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 怎么将其限制为两笔交易
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    // 下标0代表第一次买入状态， 1代表第二次买入状态，2代表第一次卖出状态，3代表第二次卖出状态
    vector<vector<int>> dp(len, vector<int>(4, 0));
    // dp[len-1][3]可以保证最大的原因就是dp[0][1]
    dp[0][0] = -prices[0], dp[0][1] = -prices[0]; // 如果是第一次买入的话,第二次买入的初始化过程
    for(int i = 1; i < len; i++) {
        dp[i][0] = max(dp[i-1][0], -prices[i]); // 不买入当前、第一次买入、第二次买入三种情况
        dp[i][1] = max(dp[i-1][1], dp[i-1][2]-prices[i]);
        dp[i][2] = max(dp[i-1][2], dp[i-1][0]+prices[i]); // 第一次已经卖出，本次不卖和 本次第一次卖出
        dp[i][3] = max(dp[i-1][3], dp[i-1][1]+prices[i]);
    }
    return dp[len-1][3];
}