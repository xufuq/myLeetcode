#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > result;
vector<int> path;

void subsetsWithDup(vector<int>& nums, int start) {
    result.push_back(path);
    int lastNum=-20;
    for(int i=start; i<nums.size(); ++i){
        if(lastNum == nums[i]) continue;
        lastNum = nums[i];
        path.push_back(nums[i]);
        subsetsWithDup(nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    subsetsWithDup(nums, 0);
    return result;
}