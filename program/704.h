//
// Created by Dell on 2021/5/27.
//

#ifndef PROGRAM_NO704_H
#define PROGRAM_NO704_H
#include "vector"

using namespace std;

int search(vector<int>& nums, int target) {
    if (nums.size()==0)
        return -1;
    else{
        int start=0, end=nums.size()-1;
        while (end-start>=0){
            int middle = (end+start)/2;
            if (nums[middle]>target)
                end=middle-1;
            else if (nums[middle]<target)
                start=middle+1;
            else
                return middle;
        }
            return -1;
    }
}


#endif //PROGRAM_NO704_H
