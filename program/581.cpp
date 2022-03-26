#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "math.h"

using namespace std;


// 官方题解的第二个解法值得学习，
// 先将数组分为三个，这样便于对比
int findUnsortedSubarray(vector<int>& nums) {
    vector<int> incrVisited;
    incrVisited.push_back(0);
    int leftIndex=nums.size(), rightIndex=leftIndex;
    for(int i=1; i<nums.size(); ++i){
        if(nums[i]<nums[incrVisited.back()]){
            for(auto it=incrVisited.rbegin(); it!=incrVisited.rend();++it){
                if(nums[*it]>nums[i]) {
                    leftIndex = min(leftIndex, *(it-1));
                    break;
                }
            }
            rightIndex=i;
        } else if(nums[i]>nums[incrVisited.back()]) incrVisited.push_back(i);
    }
    return rightIndex-leftIndex==0?0:rightIndex-leftIndex+1;
}

// left 、right是左右两侧能够取到的有序数组的范围
// left从最后面开始找，right从最前面开始找
int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int maxn = INT_MIN, right = -1;
    int minn = INT_MAX, left = -1;
    for (int i = 0; i < n; i++) {
        if (maxn > nums[i]) {
            right = i;
        } else {
            maxn = nums[i];
        }
        if (minn < nums[n - i - 1]) {
            left = n - i - 1;
        } else {
            minn = nums[n - i - 1];
        }
    }
    return right == -1 ? 0 : right - left + 1;
}