#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

// int maxLen=0;
// int count=1;

// // 时间复杂度超了， 官方题解用动态规划做
// void findNumberOfLIS(vector<int>& nums, stack<int> &path, int curIndex) {
//     if(curIndex==nums.size()) return;
//     findNumberOfLIS(nums, path, curIndex+1);
//     if(path.empty() || nums[curIndex]>path.top()) {
//         path.push(nums[curIndex]);
//         if(maxLen<path.size()) {
//             maxLen=path.size();
//             count=1;
//         } else if(maxLen==path.size()) 
//             ++count;
//         findNumberOfLIS(nums, path, curIndex+1);
//         path.pop();
//     }
// }

// int findNumberOfLIS(vector<int>& nums) {
//     stack<int> path;
//     findNumberOfLIS(nums, path, 0);
//     return count;
// }

// 动态规划，两个数组维护，比较难想
int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size(), maxLen=1, result=0;
    // dp维护包含当前元素的最大长度
    // count维护此种情况的数量
    vector<int> dp(n+1, 1), count(n+1, 1);
    dp[0]=0, count[0]=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<i;++j) {
            if(nums[i-1]>nums[j-1]) {
                if(dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(dp[j]+1==dp[i])
                    count[i]+=count[j];
                maxLen=max(maxLen,dp[i]);
            }
        }
    }
    for(int i=1;i<=n;++i) {
        if(dp[i]==maxLen)
            result+=count[i];
    }
    return result;
}