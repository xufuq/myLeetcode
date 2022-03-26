#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>
#include "math.h"
using namespace std;

// 即求出连续的数字区间
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> results;
    if(nums.size() == 0) return results;
    else if(nums.size() == 1) {
        results.push_back(to_string(nums[0]));
        return results;
    }
    int sIndex = 0;
    results.push_back(to_string(nums[0]));
    for(int i=1;i<nums.size();i++) {
        if(nums[i]!=nums[i-1]+1) {
            if(i-1>sIndex) 
                results.back()+="->"+to_string(nums[i-1]);
            results.push_back(to_string(nums[i]));
            sIndex=i;
        }
    }
    if(sIndex<nums.size()-1)
        results.back()+="->"+to_string(nums[nums.size()-1]);
    return results;
}