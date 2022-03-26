#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for(int i = 1; i < nums.size();++i)
        nums[i]+=nums[i-1];
    return nums;
}