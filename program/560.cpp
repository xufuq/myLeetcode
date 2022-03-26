#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "math.h"

using namespace std;

// 哈希表优化
int subarraySum(vector<int>& nums, int k) {
    for(int i = 1; i < nums.size();++i)
        nums[i] += nums[i-1];
    nums.insert(nums.begin(), 0);
    unordered_map<int, int> myset;
    int result=0;
    for(auto &n : nums){
        result += myset[n-k];
        ++myset[n-k];
    }
    return result;
}