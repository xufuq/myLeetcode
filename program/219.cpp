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

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i])) 
            if(i-mp[nums[i]].back()<=k) return true;
        mp[nums[i]].push_back(i);
    }
    return false;
}