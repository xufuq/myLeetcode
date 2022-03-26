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

int findShortestSubArray(vector<int>& nums) {
    int start = 0, minLen=INT_MAX, du=0;
    for(int i = 0; i < nums.size();++i) {
        if(nums[i]!=nums[start]) {
            du=max(du,i-start);
            start=i;
        }
    }
    start=0;
    unordered_map<int, int> numCount;
    for(int i=0; i<nums.size(); i++) {
        ++numCount[nums[i]];
        if(numCount[nums[i]]==du) {
            while(nums[start]!=nums[i]) ++start;
            minLen=min(minLen, i-start+1);
            ++start;
            --numCount[nums[i]];
        }
    }
    numCount.clear();
    return minLen;
}