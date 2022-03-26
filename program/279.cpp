#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>

using namespace std;


int numSquares(int n) {
    if(n<4) return n;
    vector<int> dp(n, 0);
    dp[0]=1;
    for(int i=1;i<=n/2;++i){
        for(int j=i;j<=n;++j){
            if(dp[j]==0) dp[j]=dp[j-i]+1;
            else dp[i] = min(dp[j], dp[j-i]+1);
        }
    }
    return dp[n];
}