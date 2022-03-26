#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

// 这种可以很快的直接写出动态规划方程
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    for(int i=n-1; i>=0; i--){
        if(i==n-1) dp[i]=nums[i];
        else if(i==n-2) dp[i] = max(nums[i], nums[i+1]);
        else{
            dp[i]=max(nums[i]+dp[i+2], dp[i+1]);
        }
    }
    return dp[0];
}