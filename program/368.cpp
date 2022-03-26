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

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxLen=1, maxIndex=0, n=nums.size();
    vector<vector<int>> dp(n, vector<int>(2)); //第一个元素存他的基的坐标，第二个存当前的个数
    vector<int> result;
    for(int i=0;i<nums.size();++i) {
        int k=i-1;
        for(;k>=0;--k) {
            if(nums[i]%nums[k]==0 && dp[k][1]+1>dp[i][1]) {
                dp[i][0]=k;
                dp[i][1]=dp[k][1]+1;
                if(dp[i][1]>maxLen) {
                    maxLen=dp[i][1];
                    maxIndex=i;
                }
            }
        }
        if(dp[i][1]==0) {
            dp[i][0]=-1;
            dp[i][1]=1;
        }
    }
    if(maxLen==1) {
        result.push_back(nums[0]);
        return result;
    }
    while(maxIndex!=-1) {
        result.push_back(nums[maxIndex]);
        maxIndex=dp[maxIndex][0];
    }
    reverse(result.begin(), result.end());
    return result;
}