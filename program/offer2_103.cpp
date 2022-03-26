#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>

using namespace std;


int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    dp[0]=0;
    for(auto c : coins) {
        for(int i=c;i<=amount;++i){
            if(dp[i]!=-1 && dp[i-c]!=-1)
                dp[i] = min(dp[i], dp[i-c]+1);
            else if(dp[i-c]!=-1)
                dp[i] = dp[i-c]+1;
        } 
    }
    return dp[amount];
}

