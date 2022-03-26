#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 依然是平均分
// 查找小于等于一半的最大重量
int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    // sort(nums.begin(), nums.end());
    int bagWeight = sum/2;
    vector<int> dp(bagWeight+1, 0);
    for(int i = 0; i < stones.size();++i){
        for(int j=bagWeight;j>0;--j){
            if(stones[i]>j) break;
            else dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
        }
    }
    return sum-2*dp[bagWeight];
}