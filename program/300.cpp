#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

// 先用递归是一下, 可以实现，但是超时
// int lengthOfLIS(vector<int>& nums, int minStart, int startIndex) {
//     if( startIndex == nums.size()) return 0;
//     if(nums[startIndex] <= minStart) return lengthOfLIS(nums, minStart, startIndex+1);
//     return max(lengthOfLIS(nums, minStart, startIndex+1), lengthOfLIS(nums, nums[startIndex], startIndex+1)+1);
// }

// 用map记录已经查询过的值
// 这种方式也超时了
// int lengthOfLIS(vector<int>& nums, map<vector<int>, int> &memMap,int minStart, int startIndex) {
//     if(startIndex == nums.size()) return 0;
//     if(nums[startIndex] <= minStart) return lengthOfLIS(nums, memMap, minStart, startIndex+1);
//     vector<int> vec = {minStart, startIndex};
//     if(memMap.find(vec) == memMap.end()) 
//         memMap[vec] = max(lengthOfLIS(nums, memMap, minStart, startIndex+1), lengthOfLIS(nums, memMap, nums[startIndex], startIndex+1)+1);
//     return memMap[vec];
// }

// int lengthOfLIS(vector<int>& nums) {
//     // <最小值，起始点> 对应数量
//     map<vector<int>, int> memMap;
//     return lengthOfLIS(nums, memMap, INT32_MIN, 0);
// }   

// dp[i]表示i之前包括i的最长上升子序列
// 这个要包括当前i的特点的对于这个方法很重要
// 没有想到这个方法就是这里被约束了
// 而且对每一个子序列分别进行找最大子序列的操作
// 因为比较的时候比如dp[j],最后一个元素肯定是nums[j],所以直接和他比较就可以了
int lengthOfLIS(vector<int>& nums) {
    int result = 0, n = nums.size();
    vector<int> dp(n, 1); // 最少应该都包括自身
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(nums[i]>nums[j]) nums[i] = max(nums[i], nums[j]+1);
        }
        if(result<nums[i]) result = nums[i];
    }
    return result;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout <<lengthOfLIS(nums) << endl;
}