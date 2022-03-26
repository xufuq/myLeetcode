#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size(), inIndex = 0, outIndex = 0, profit = 0;
    bool inOut = false; // false 代表当前需要买入, true代表当前需要卖出
    for(int i = 0; i < len; ++i) {
        if(!inOut && prices[i] < prices[inIndex]) inIndex = i;
        else if(!inOut && prices[i] > prices[inIndex]+fee) { // 此刻买入一定是能赚的，买入
            profit -= prices[inIndex]+fee; // 买入的钱和手续费一块减
            // cout << inIndex << " ";
            outIndex = i;
            inIndex=i;
            inOut=true;
        }
        else if(inOut && prices[i]>prices[outIndex]) outIndex=i; // 卖出价格变高
        else if(inOut && (prices[i]+fee<prices[outIndex])){ // 此刻卖出不耽误后边挣钱 || 到达最后不卖不行
            profit += prices[outIndex];
            // cout << outIndex << endl;
            inIndex=i;
            outIndex=i;
            inOut=false;
        }
    }
    if(inOut)
        profit += prices[outIndex];
    return profit;
}

// 动态规划版本
int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    // 实际上只需要一个2*2的数组即可
    vector<vector<int>> dp(len, vector<int>(2,0));
    dp[0][0] = -prices[0]-fee;
    for(int i=1;i< len;++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]-fee);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }
    return dp[len-1][1];
}

int main(){
    vector<int> prices={1,3,2,8,4,9};
    cout << maxProfit(prices, 2);
}