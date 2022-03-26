#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<vector<int> > result;
vector<int> path;

// 不能对输入进行排序，要保持原始顺序

void findSubsequences(vector<int>& nums, int start) {
    if(path.size()>1) 
        result.push_back(path);
    set<int> usedNum;
    for(int i = start; i < nums.size();++i) {
        if(usedNum.find(nums[i])!=usedNum.end() || (!path.empty() &&nums[i]<path.back())) continue;
        usedNum.insert(nums[i]);
        path.push_back(nums[i]);
        findSubsequences(nums, i+1);
        path.pop_back();
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    findSubsequences(nums, 0);
    return result;
}

int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    findSubsequences(nums);
    cout << result.size() << endl;
    for(auto v : result){
        for(auto n : v)
            cout << n << " ";
        cout << endl;
    }
}