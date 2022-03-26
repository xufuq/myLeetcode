#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxIndex=0, minIndex=0, currentProfit=0; // min时买入，max时卖出
    for(int i=1;i<prices.size();++i){
        if(prices[i]>prices[maxIndex]) // 更新卖出点
            maxIndex=i;
        else if(prices[i]<prices[minIndex]){ // 更新买入点和收益
            currentProfit = max(currentProfit, prices[maxIndex] - prices[minIndex]);
            maxIndex=i, minIndex=i;
        }
    }
    currentProfit = max(currentProfit, prices[maxIndex] - prices[minIndex]);
    return currentProfit;
}


// 动态规划版本
int maxProfit(vector<int>& prices) {
    int len = prices.size();
    // 下标0代表当前是买入状态，持有股票
    // 下标1代表当前是卖出状态，不持有股票
    vector<int> dp(len, vector<int>(2, 0));
    dp[0][0] = -prices[0], dp[0][1] = 0;
    for(int i=1;i<len;++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }
    return dp[len-1][1];
}