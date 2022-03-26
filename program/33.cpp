#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 暴力查找
int search(vector<int>& nums, int target) {
    if(nums[0]<=target){
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==target) return i;
            else if(nums[i]>target) return -1;
        }
    }
    else if(nums.back() >= target){
        for(int i=nums.size()-1; i>=0; --i){
            if(nums[i]==target) return i;
            else if(nums[i]<target) return -1;
        }
    }
    else
        return -1;
}

// 二分法，二分后至少有一半是有序的
int search(vector<int>& nums, int target) {
    int left=0, right=nums.size()-1, mid = (left+right)/2;
    if(right==-1) return -1;
    else if(right==0) return nums[0]==target?0:-1;
    while(left<=right){
        if(nums[left]<=nums[mid]){ // 左半部分有序
            if(nums[mid]==target) return mid;
            // else if(nums[left]==target) return left;
            else if(nums[left]<=target && nums[mid]>target) {
                right=mid;
                mid = (left+right)/2;
            } else { //在另外一半
                left=mid+1;
                mid= (left+right)/2;
            }
        }
        else { // 右半部分有序
            if(nums[mid]==target) return mid;
            else if(nums[right]>=target && nums[mid]<target){
                left=mid+1;
                mid= (left+right)/2;
            } else {
                right=mid;
                mid= (left+right)/2;
            }
        }
    }
    return -1; //
}