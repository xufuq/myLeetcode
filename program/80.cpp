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
#include <queue>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int left=1, right=1, curCount=1, curNum=nums[0];
    while(right<nums.size()) {
        if(nums[right]==curNum)
            ++curCount;
        else {
            curNum=nums[right];
            curCount=1;
        }
        if(curCount<3) {
            nums[left]=curNum;
            ++left;
        }
        ++right;
    }
    nums.erase(nums.begin()+left, nums.end());
    return left;
}