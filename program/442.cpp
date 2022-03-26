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
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for(int i=0; i<nums.size(); i++) {
        if(nums[abs(nums[i])]<0) 
            result.push_back(abs(nums[i]));
        else 
            nums[abs(nums[i])]=-nums[abs(nums[i])];
    }
    return result;
}