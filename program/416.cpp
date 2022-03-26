#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 两个背包平均，所以一个背包占总和一般
// 将背包容量设置为总和一半，最大化其容量即可
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2) return false;
    // sort(nums.begin(), nums.end());
    int bagWeight = sum/2;
    vector<int> dp(bagWeight+1, 0);
    for(int i = 0; i < nums.size();++i){
        for(int j=bagWeight;j>=nums[i];--j){
            dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
        }
    }
    return dp[bagWeight]==bagWeight;
}