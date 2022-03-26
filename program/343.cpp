#include <vector>
#include <algorithm>
using namespace std;

int integerBreak(int n) {
    vector<int> dp(n+1, 1);
    dp[0]=1, dp[1]=1;
    for(int i=2;i<n;++i){
        dp[i]=i;
        for(int j=0, k=i;j<=k;++j, --k) // 这里包含不拆分的情况
            dp[i]=max(dp[i],dp[j]*dp[k]);
    }
    dp[n]=n-1; // 最少也要是1*(n-1),因为必须要拆分
    for(int j=1, k=n-1;j<=k;++j, --k)
        dp[n]=max(dp[n],dp[j]*dp[k]);
    return dp[n];
}