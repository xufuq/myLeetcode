#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

// 这道题应该用动态规划或者回溯算法
// 这里先用动态规划做，看解析是怎么做的

// 上面想的太复杂了，起始就是找序列上的极值


int wiggleMaxLength(vector<int>& nums) {
    int preDiffs = 0, curDiffs = 0;
    int count = 1; // 第一个肯定是一个极值
    for(int i=1; i<nums.size(); ++i){
        curDiffs=nums[i]-nums[i-1];
        if((curDiffs<0 && preDiffs>=0) || (curDiffs>0 && preDiffs<=0)){
            ++count;
            preDiffs=curDiffs;
        }
    }
    return count;
}

