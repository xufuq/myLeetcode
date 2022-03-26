#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > result;

void subsets(vector<int>& nums, int start, vector<int>& path) {
    result.push_back(path);
    for(int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        subsets(nums, i+1, path);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    subsets(nums, 0, path);
    return result;
}