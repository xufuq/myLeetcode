//
// Created by Dell on 2021/5/27.
//

#ifndef PROGRAM_NO27_H
#define PROGRAM_NO27_H

#include "vector"
#include "iostream"

using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.size()>0){
        int left=0, right=nums.size()-1;
        while (left<=right){
            if (nums[left]==val && nums[right]!=val){ // 交换
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
            }
            else if (nums[left]==val && nums[right]==val)
                right--;
            else if (nums[left]!=val && nums[right]==val)
                left++, right--;
            else
                left++;
        }
    }
    int count=0;
    for (auto num : nums) {
        if (num==val)
            return count;
        else{
            ++count;
            cout << num << " ";
        }
    }
    return count;
}

#endif //PROGRAM_NO27_H
