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

// 最长的相邻的两个元素的长度
int findLHS(vector<int>& nums) {
    map<int, int> mp;
    for(auto &n : nums)
        ++mp[n];
    auto left=mp.begin();
    auto right=++mp.begin();
    int result=0;
    while(right != mp.end()) {
        if(right->first==left->first+1) 
            result=max(right->second+left->second, result);
        ++left;
        ++right;
    }
    return result;
}