#include <vector>


// 记录当前最靠前的一个正数和最靠后的负数之间的数的和，如果小于0就放弃掉

using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0, maxSum = INT32_MIN;
    for(int i=0; i<nums.size(); ++i) {
        if(sum<=0){
            sum = 0;

        sum += nums[i];
        if(sum>maxSum)
            maxSum = sum;
    }
    return maxSum;
}

// 动态规划做
// 这个动态规划不对
int maxSubArray(vector<int>& nums) {
    int len = nums.size(), result=nums[0];
    vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
    for(int i=0;i<len;++i){
        for(int j=i;j>=0;++j){
            dp[i][j] = dp[i][j+1] + nums[j];
            if(dp[i][j]>result) result=dp[i][j];
        }
    }
    return result;
}

// 官方题解，其实和我上面写的贪心算法的想法是一样的
// 只不过上面的动态规划做法一直在纠结记录开始、结束起点的问题
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式，这种情况就是dp[i - 1]<0,直接舍去就可以了
        if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
    }
    return result;
}