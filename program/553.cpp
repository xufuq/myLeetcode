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

// 用数学思想来做
string optimalDivision(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return to_string(nums[0]);
    if(n==2) return to_string(nums[0])+"/"+to_string(nums[1]);
    string result=to_string(nums[0])+"/(";
    for(int i=1;i<n;++i)
        result+=to_string(nums[i])+"/";
    result.pop_back();
    result+=")";
    return result;
}