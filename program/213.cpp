#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>
using namespace std;

// 在不包括nums[0]时计算一次最大，在不包括nums[n-1]时计算一次最大
class Solution {
public:
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp(n, 0);
    for(int i=n-2; i>=0; i--){ // 包含0，不包含n-1
        if(i==n-2) dp[i]=nums[i];
        else if(i==n-3) dp[i] = max(nums[i], nums[i+1]);
        else{
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }
    }
    int currentMax = dp[0];
    for(int i=n-1; i>=1; i--){ // 包含0，不包含n-1
        if(i==n-1) dp[i]=nums[i];
        else if(i==n-2) dp[i] = max(nums[i], nums[i+1]);
        else{
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }
    }
    currentMax = max(currentMax, dp[1]);
    return currentMax;
}
};