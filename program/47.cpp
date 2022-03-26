#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

vector<vector<int> > result;
vector<int> path;

// set记录
void permuteUnique(vector<int>& nums, vector<bool>& isUsed) {
    if(path.size()==nums.size()) result.push_back(path);
    else{
        unordered_set<int> usedInThisLevel;
        for(int i = 0; i < nums.size();++i){
            if(isUsed[i] || usedInThisLevel.find(nums[i])!=usedInThisLevel.end()) continue;
            usedInThisLevel.insert(nums[i]);
            isUsed[i]=true;
            path.push_back(nums[i]);
            permuteUnique(nums, isUsed);
            isUsed[i]=false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> isUsed(nums.size());
    permuteUnique(nums, isUsed);
    return result;
}

// 先排序
void permuteUnique(vector<int>& nums, vector<bool>& isUsed) {
    if(path.size()==nums.size()) result.push_back(path);
    else{
        int lastNum=-11;
        for(int i = 0; i < nums.size();++i){
            if(isUsed[i] || lastNum==nums[i]) continue;
            lastNum=nums[i];
            isUsed[i]=true;
            path.push_back(nums[i]);
            permuteUnique(nums, isUsed);
            isUsed[i]=false;
            path.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<bool> isUsed(nums.size());
    permuteUnique(nums, isUsed);
    return result;
}