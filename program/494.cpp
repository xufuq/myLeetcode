#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 用dp中的数字记录有多少种合成当前数字的组合
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0); // 找到a==(sumof(nums)+target)/2
    if((sum+target)%2) return 0; // 无法完成整除
    int mid, count = 0;
    if(sum+target>=0) mid = (sum+target)/2;
    else mid = (sum-target)/2;
    vector<int> dp(mid+1, 0);
    dp[0]=1;//dp[0]应该设置为1，这样的话当当前数字和目标数字相等时，要加1，也就是dp[0]
    for(auto n : nums) {
        for(int j=mid;j>=n;--j){
            dp[j] = dp[j] + dp[j-n];
        }
    }
    return dp[mid];
}