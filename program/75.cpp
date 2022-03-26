#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 可以直接sort，这里用双指针做
// 
void sortColors(vector<int>& nums) {
    int i=0, j=nums.size()-1;
    for(int k=0;k<=j;++k) {
        if(nums[k]==0) {
            swap(nums[i], nums[k]); // 这里换过来的肯定是1
            ++i;
        }
        if(nums[k]==2){
            swap(nums[k], nums[j]);
            --j;
            if(nums[k]!=1) // 这个判断条件很关键
                --k;
        }
    }
}

// 自己的方法
void sortColors(vector<int>& nums) {
    int i=0, j=nums.size()-1;
    int k=0;
    while(k<=j){
        if(nums[k]==0){
            swap(nums[i], nums[k]);
            ++i, ++k;
        }
        else if(nums[k]==2){
            while(nums[k]==2){
                swap(nums[k], nums[j]);
                --j;
            }           
        }
        else ++k;
    }
}