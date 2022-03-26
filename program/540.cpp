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
#include <queue>
using namespace std;

// 二分法控制时间复杂度
int singleNonDuplicate(vector<int>& nums) {
    int start = 0, end = nums.size(), mid=(start+end)/2;
    while(start < end) {
        if(mid>0 && nums[mid]==nums[mid-1]) {
            if((mid-1-start)%2==0)  // 单独的在后半部分
                start = mid+1;
            else
                end=mid-2;
        }
        else if(mid<nums.size()-1 && nums[mid]==nums[mid+1]) {
            if((mid-start)%2==0)
                start=mid+2;
            else
                end=mid-1;
        }
        else
            return mid;
        mid=(start+end)/2;
    }
    return mid;
}