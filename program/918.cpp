#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>
using namespace std;

// 可以用双指针来做
// 常规的不连接头尾的话，就是找区间最大值
// 如果最大值在头尾连接的部分，那么找到中间最小的值，再用总和减去就是首尾连接的最大值了
int maxSubarraySumCircular(vector<int>& nums) {
    int sIndex=0, sum=0, maxSum=INT_MIN, n=nums.size(), minSum=INT_MAX, total=0;
    for(int i=0; i<n; i++) {
        total+=nums[i];
        sum+=nums[i];
        if(sum>maxSum) 
            maxSum=sum;
        if(sum<=0) 
            sum=0;
    }
    sum=0;
    for(int i=0;i<n-1;++i) { // 这里限制在n-1是因为防止有全为负数的情况，而且这种情况本省就是头尾相接，所以至少要保留一个尾元素
        sum+=nums[i];
        if(minSum<nums[i])
            minSum=nums[i];
        if(sum>=0)
            sum=0;
    }
    
    return max(maxSum, total-minSum);
}

// 超出时间限制
int maxSubarraySumCircular(vector<int>& nums) {
    int sIndex=0, sum=0, maxSum=INT_MIN, n=nums.size(), headMaxSum=INT_MIN;
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i=0;i<n;++i) {
        dp[i][i]=nums[i];
        maxSum=max(maxSum, dp[i][i]);
    }
    for(int i=n-2;i>=0;--i) {
        for(int j=i+1;j<n;++j) {
            dp[i][j]=dp[i][j-1]+nums[j];
            maxSum=max(maxSum, dp[i][j]);
        }
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<i;++j) {
            int index=(j-1+n)%n;
            dp[i][j]=dp[i][index]+nums[j];
            maxSum=max(maxSum, dp[i][j]);
        }
    }
    return maxSum;
}