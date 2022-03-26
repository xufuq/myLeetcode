#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size()<3) return 0;
    int sIndex=0, result=0, n_c=nums[1]-nums[0];
    for(int i=1;i<nums.size();++i) {
        if(nums[i]-nums[i-1]!=n_c) {
            int len=i-sIndex;
            if(len>2) 
                result+=(len-2)*(len-1)/2; // 连续数求和
            sIndex=i-1;
            n_c=nums[i]-nums[i-1];
        }
    }
    int len=nums.size()-sIndex;
    if(len>2) 
        result+=(len-2)*(len-1)/2;
    return result;
}