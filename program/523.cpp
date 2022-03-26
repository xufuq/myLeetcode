#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

// 如果一段数据的余数相等，那么必定是k的倍数
bool checkSubarraySum(vector<int>& nums, int k) {
    // 用一个二维数组记载和
    int n=nums.size(), sum = 0;
    unordered_map<int, int> mp;
    for(int i=0;i<nums.size();i++) {
        sum=(sum+nums[i])%k;
        if(sum==0 && i>0) return true;
        else if(mp.count(sum)) { // 之前已经出现过一次
            if(i-mp[sum]>1) return true;
        }
        else 
            mp[sum]=i;
    }
    return false;
}