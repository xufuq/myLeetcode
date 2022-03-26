#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// 这里用求和算法浪费了时间
// 这里用下标的方法寻址更方便
int minSubArrayLen(int target, vector<int>& nums) {
    auto leftP = nums.begin(), rightP = nums.begin()+1, numsEnd = nums.end();
    int result = nums.size()+1, currentLen = 1, sum=*leftP;
    while (leftP!=nums.end()) {
        if (target > sum && currentLen < result){
            if(rightP!=numsEnd){
                sum += *rightP;
                ++rightP; 
                ++currentLen;
            }
            else
                break;
        }
        else if (target <= accumulate(leftP, rightP, 0) && currentLen <= result){
            result = currentLen;
            sum -= *leftP;
            ++leftP;
            --currentLen;
        }
        else{
            sum -= *leftP + *(leftP+1);
            leftP += 2;
            currentLen -= 2;
        }
        if(result==1)
            break;
    }
    return result==nums.size()+1 ? 0 : result;
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    cout << minSubArrayLen(7, nums) << endl;
}