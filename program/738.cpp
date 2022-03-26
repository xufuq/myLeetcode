#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

int monotoneIncreasingDigits(int n) {
    int result=0;
    vector<int> nums;
    while(n!=0) {
        nums.push_back(n%10);
        n /= 10;
    }
    reverse(nums.begin(), nums.end()); // 高位在前
    bool isIncrease=true;
    int afterIndex = nums.size();
    for(int i=1; i<nums.size(); i++){
        if(nums[i]<nums[i-1]){
            for(int j=i-1;j>=0;--j){
                if(nums[j]>nums[j+1]){
                    nums[j]-=1;
                    afterIndex=j;
                }
            }
        break;
        }
    }
    for(int i=0; i<nums.size();++i){
        if(i<=afterIndex)
            result = result*10+nums[i];
        else
            result = result*10+9;
    }
    return result;
}

// 推荐题解把数字转成了string，然后就可以对数字按位操作

int monotoneIncreasingDigits(int n) {
    string num = to_string(n);
    int flag=num.size();
    for(int i=num.size()-1;i>0;--i){
        if(num[i]<num[i-1]){
            num[i-1]--;
            flag=i;
        }
    }
    for(int i=flag;i<num.size();++i)
        num[i]='9';

    return stoi(num);
}

int main(){
    int n = 1233;
    cout << monotoneIncreasingDigits(n);
}