#include <vector>

using namespace std;

vector<vector<int> > result;

void combinationSum3(vector<int> &nums, int currentIndex, int k, int n){
    if(k == 0 && n==0){
        result.push_back(nums);
        return;
    }
    else if(k > 0){
        for(int i=currentIndex; i < 10 && n>=i;++i){
            nums.push_back(i);
            combinationSum3(nums, i+1, k-1, n-i);
            nums.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums;
    combinationSum3(nums,1,k,n);
    return result;
}