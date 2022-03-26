#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    map<int, int> count;
    for(int i = 0; i < nums.size();++i)
        ++count[nums[i]];
    int n=count.size();
    if(n==1) 
        return nums[0]*count[nums[0]];
    vector<int> dp(n+1);
    auto it=count.begin();
    dp[0]=0, dp[1]=it->first*it->second;
    int last=it->first, i=2;
    ++it;
    while(it!=count.end()) {
        if(it->first==last+1)  // 相邻数字，已经被删除
            dp[i]=max(dp[i-2]+it->first * it->second, dp[i-1]);
        else 
            dp[i]=max(dp[i-2]+it->first * it->second, dp[i-1]+it->first * it->second);
        last=it->first;
        ++it, ++i;
        
    }
    return dp.back();
}