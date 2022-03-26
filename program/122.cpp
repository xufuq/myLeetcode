#include <vector>

using namespace std;

// 找峰值进行买卖

int maxProfit(vector<int>& prices) {
    bool inOut = false; // false代表当前需要买入，true代表当前需要卖出
    int profit = 0, inIndex = 0; //
    for(int i = 0; i < prices.size()-1;++i){
        if(!inOut && prices[i]<prices[i+1]){
            inIndex=i+1; //
            inOut=!inOut;
        }
        else if(inOut && prices[i]>prices[i+1]){
            profit += prices[i]-prices[inIndex];
            inOut=!inOut;
        }
    }
    if(inOut)
        profit += prices.back()-prices[inIndex];
    return profit;
}