#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    if(nums[0]>nums[1]) return 0;
    int len=nums.size();
    if(nums[len-1]>nums[len-2]) return len-1;
    for(int i=1; i<len-1; )
        if(nums[i]>nums[i+1]) {
             if(nums[i]>nums[i-1]) return i;
             else i+=2;
        }
        else if(nums[i]==nums[i+1]) i+=2;
        else ++i;

    return -1;
}