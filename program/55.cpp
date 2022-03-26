#include <vector>
#include <iostream>

using namespace std;

// 如何保证其不经过0
// 先找0
// 只要0的前面一个数大于1就行，或第二个数大于2，或第三个数大于3.。。。就行


bool canJump(vector<int>& nums) {
    int mostFar = 0;
    for(int i = 0; i < nums.size()-1;++i){
        if(nums[i]+i > mostFar) mostFar = i+nums[i];
        if(nums[i] == 0 && mostFar <= i)
                return false;
    }
    return true;
}

int main(){
    vector<int> nums={2, 0, 0};
    cout << canJump(nums);
}