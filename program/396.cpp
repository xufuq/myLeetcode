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
#include "math.h"
using namespace std;

// 向右平移k个位置
int maxRotateFunction(vector<int>& nums) {
    int maxK=0, n=nums.size();
    int sum=accumulate(nums.begin(),nums.end(), 0), maxSum=sum, lastSum=sum;
    for(int i=1;i<nums.size();i++) {
        int curSum=lastSum+sum-n*nums[n-i];
        lastSum=curSum;
        if(curSum>maxSum) {
            maxSum=curSum;
            maxK=i;
        }
    }
    sum=0;
    for(int i=0;i<nums.size();i++) {
        if(i<maxK)
            sum+=i*nums[n-maxK+i];
        else
            sum+=i*nums[i-maxK];
    }
    return sum;
}