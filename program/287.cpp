#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 用数组索引的做法
int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;++i) {
        if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
        else nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
    }
    return -1;
}