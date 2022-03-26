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

int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int count=1;
    for(int i=1; i<nums.size();++i) {
        if(nums[i]!=nums[i-1]) ++count;
        if(count==3) return nums[i];
    }
    return nums[0];
}