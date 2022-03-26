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

int findPairs(vector<int>& nums, int k) {
    int result=0;
    unordered_set<string> pairSet;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1;j<nums.size(); j++) {
            if(abs(nums[i]-nums[j])==k && pairSet.count(to_string(nums[i])+"#"+to_string(nums[j]))==0) {
                pairSet.insert(to_string(nums[i])+"#"+to_string(nums[j]));
                ++result;
            }
        }
    }
    return result;
}

// 高赞解使用哈希表记录访问过的数，然后直接用哈希表找与当前数差为k的数字是否存在