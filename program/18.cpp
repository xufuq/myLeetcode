#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    if(nums.size() < 4) return result;
    for(int i = 0; i < nums.size()-3;++i){
        if((target<=0 && nums[i]>0) || (target>=0 && nums[i]>target)) return result;
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j = nums.size() - 1; j >i+2;--j){
            if((target>=0 && nums[j]<0) || (target<=0 && nums[j]<target)) break;
            if(j<nums.size()-1 && nums[j]==nums[j+1]) continue;
            int m=i+1, n=j-1;
            while(m<n){
                if(nums[i] + nums[m] + nums[n] + nums[j]==target){
                    result.push_back({nums[i], nums[m], nums[n], nums[j]});
                    while(m+1 < n && nums[m+1]==nums[m])  ++m;
                    while(n-1 > n && nums[n-1]==nums[n])  --n;
                    ++m;
                    --n;
                }
                else if(nums[i] + nums[m] + nums[n] + nums[j]<target)
                    ++m;
                else
                    --n;
            }
        }
    }
    return result;
}

int main(){
    vector<int> nums = {0};
    auto result = fourSum(nums, 0);
    for(auto vv : result){
        for(auto v : vv)
            cout << v << " ";
        cout << endl;
    }
}