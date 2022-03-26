#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

int missingNumber(vector<int>& nums) {
    bool isN=false;
    int zIndex;
    for(auto &n : nums) {
        if(abs(n)==nums.size()) isN=true;
        else nums[n]=-abs(nums[n]);
        
    }
    if(!isN) return nums.size();
    for(int i=0; i<nums.size();++i)  {
        if(nums[i]>0) return i;
        if(nums[i]==0) zIndex=i;
    }
        
    return zIndex;
}