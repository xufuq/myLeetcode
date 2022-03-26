#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
#include <numeric>
using namespace std;

bool checkPossibility(vector<int>& nums) {
    bool valid=true;
    for(int i=0; i<nums.size()-1;++i) {
        if(nums[i]>nums[i+1]) {
            if(valid) {
                if(i==0 || nums[i+1]>=nums[i-1]) {
                    nums[i]=nums[i+1];
                }
                else {
                    nums[i+1]=nums[i];
                }
                valid=false;
            }
            else return false;
        }
    }
    return true;
}