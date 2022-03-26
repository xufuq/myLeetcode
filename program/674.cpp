#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    if(nums.size()<2) return nums.size();
    vector<int> dp(n,1);
    int results = 0;
    for(int i = 1; i < n; ++i) {
        if(nums[i]>nums[i-1]) dp[i] = dp[i-1] + 1;
        else if(dp[i-1]>results) results = dp[i-1];
    }
    if(dp[n-1]>results) results = dp[n-1];
    return results;
}