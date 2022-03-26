#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> pre;
    for(int i=0; i<nums.size(); i++){
        if(pre.find(nums[i]) != pre.end())
            return {pre[nums[i]], i};
        pre.insert(pair<int,int>(target-nums[i], i));
    }
}