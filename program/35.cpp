#ifndef PROGRAM_NO35_H
#define PROGRAM_NO35_H

#include "vector"
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int Start=0,End=nums.size()-1,Middle=End/2;
    if(nums.size() > 2){
        while (Start != End-1){
            if(nums[Middle]>target){
                End=Middle;
                Middle=(Start+End)/2;
            }
            else if(nums[Middle]<target){
                Start=Middle;
                Middle=(Start+End)/2;
            } else
                return Middle;
        }
    }
    if(target>nums[End])
        return End+1;
    else if (target<=nums[Start])
        return Start;
    else
        return End;
}

#endif //PROGRAM_NO35_H
