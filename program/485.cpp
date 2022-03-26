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

int findMaxConsecutiveOnes(vector<int>& nums) {
    int start = 0, maxLen=0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i]==0) {
            maxLen = max(maxLen, i-start);
            start = i+1;
        }
    }
    maxLen = max(maxLen, (int)nums.size()-start);
    return maxLen;
}