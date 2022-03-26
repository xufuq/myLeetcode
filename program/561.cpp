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

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < nums.size();i+=2)
        result += nums[i];
    return result;
}