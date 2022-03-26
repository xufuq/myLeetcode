#include <vector>
#include "iostream"
using namespace std;

void moveZeroes(vector<int>& nums) {
    int left=0, right=0;
    while(right<nums.size()) {
        if(nums[right]){
            swap(nums[left],nums[right]);
            left++;
        }
        right++;
    }
}

int main(){
    vector<int> nums = {2,1};
    moveZeroes(nums);
    for(auto num : nums)
        cout << num << " ";
}