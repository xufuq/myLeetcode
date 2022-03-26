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

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(auto &n:nums) ++mp[n];
    vector<int> result;
    int n=nums.size()/3;
    for(auto &m:mp) {
        if(m.second>n)
            result.push_back(m.first);
    }
    return result;
}