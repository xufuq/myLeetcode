#include <vector>
#include <iostream>

using namespace std;

// 比如第一步，找第一步范围内第一步加第二步能调到的最远范围
// 遇到0需要特殊处理，好像也不用处理，现在的策略可以实现自动规避0

int jump(vector<int>& nums) {
    if(nums.size()==1) return 0;
    int currentIndex = 0, nextIndex = 0, maxRange = 0, count = 1;
    int length = nums.size();
    while(maxRange<length-1){
        for(int i=1;i<=nums[currentIndex];++i){
            if(currentIndex+i>=length-1) return count; // 防止访问数组越界
            if(maxRange<currentIndex+i+nums[currentIndex+i]) {
                maxRange=currentIndex+i+nums[currentIndex+i];
                nextIndex=currentIndex+i;
            }
        }
        currentIndex=nextIndex;
        count++;
    }
    return count;
}