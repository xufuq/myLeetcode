#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

// void setZero(vector<int>& nums, int index){
//     int temp=nums[index];
//     nums[index]=0;
//     if(temp>0) setZero(nums, temp);
// }

// int firstMissingPositive(vector<int>& nums) {
//     int n=nums.size();
//     for(auto &num : nums) 
//         if(num<=0 || num>n) --n;
//     if(n==nums.size()) return n+1;
//     for(auto& num : nums) 
//         if(num<=0 || num>n) num=-1;
//     for(auto &num : nums){
//         if(num!=-1) setZero(nums, num);
//     }
//     for(int i=1;i<=n;++i)
//         if(nums[i]!=0) return i;
//     return n+1;
// }

// 官方题解，加负号再用abs不影响再次调用其数值访问数组元素
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]); // 关键是这一句
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};


int firstMissingPositive(vector<int>& nums) {
    for(auto& num: nums) {
        if(num<=0) num=INT_MAX;
    }
    for(int i = 0; i < nums.size(); ++i) {
        if(abs(nums[i])-1<nums.size()) 
            nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
    }
    for(int i=1;i<=nums.size(); ++i) {
        if(nums[i-1]>0) 
            return i;
    }
    return nums.size()+1;
}