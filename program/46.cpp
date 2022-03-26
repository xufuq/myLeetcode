#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<vector<int> > result;
vector<int> path;

void permute(vector<int>& nums, vector<bool>& isUsed) {
    if(path.size()==nums.size()) result.push_back(path);
    else{
        for(int i = 0; i < nums.size();++i){
            if(isUsed[i]) continue;
            isUsed[i]=true;
            path.push_back(nums[i]);
            permute(nums, isUsed);
            isUsed[i]=false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> isUsed(nums.size());
    permute(nums, isUsed);
    return result;
}