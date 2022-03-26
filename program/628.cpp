#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

int maximumProduct(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int result = INT_MIN;
    result = max(result,nums[len-1]*nums[len-2]*nums[len-3]);
    result = max(result,nums[len-1]*nums[0]*nums[1]);
    return result;
}