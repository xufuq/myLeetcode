#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;


// 这个题和之前的不同点就是数字可以重复
// 不同的组合顺序也代表不同的情况
// int combinationSum4(vector<int>& nums, int target) {
//     vector<int> dp(target+1, 0);
//     dp[0]=1;
//     for(auto n : nums) {
//         for(int i=n;i<=target;++i) {
//             dp[i]=dp[i]+dp[i-n];
//         }
//     }
//     return dp[target];
// }

// 改变遍历内外循环的顺序就可以获得不同的数组顺序
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    dp[0]=1;
    for(int i=0;i<=target;++i) {
        for(auto n : nums) {
            if (i>=n) dp[i]=dp[i]+dp[i-n];
        }
    }
    return dp[target];
}

int main(){
    vector<int> nums={1, 2, 3};
    cout << combinationSum4(nums, 4);
}