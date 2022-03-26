#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int startIndex=-1, minNum = 10001;
    for(auto &num : nums){
        if(num < 0){
            num=-num;
        }
        if (num <= minNum){
            minNum = num;
            ++startIndex;
        }
        else
            break;
    }
    int leftIndex = startIndex, rightIndex = startIndex+1, currentIndex=0;
    vector<int> result(nums.size());
    while(leftIndex>=0 && rightIndex < nums.size()){  // 两边都有时
        if(nums[leftIndex] < nums[rightIndex]){
            result[currentIndex]=pow(nums[leftIndex] ,2);
            --leftIndex;
        }
        else{
            result[currentIndex]=pow(nums[rightIndex] ,2);
            ++rightIndex;
        }
        ++currentIndex;
    }
    while(leftIndex>=0){
        result[currentIndex]=pow(nums[leftIndex] ,2);
        --leftIndex;
        ++currentIndex;
    }
    while (rightIndex<nums.size())
    {
        result[currentIndex]=pow(nums[rightIndex] ,2);
        ++rightIndex;
        ++currentIndex;
    }
    return result;
}

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result = sortedSquares(nums);
    for (auto r : result)
    {
        cout << r << " ";
    }
    cout << endl;
}