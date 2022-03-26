#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    map<int, int> countMp;
    vector<int> result(nums.size());
    result.back()=0;
    for(int i=nums.size()-1; i>=0;--i) {
        countMp[nums[i]]++; //
        for(auto it=countMp.begin(); it->first!=nums[i];++it)
            result[i]+=it->second;
    }
    return result;
}