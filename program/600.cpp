#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 动态规划，当bit[i]为0时是bit[i-1]的数量，当bit[i]为1时是bit[i-2]的数量
int findIntegers(int n) {
    if(n==1) return 2;
    // 先求出最高位的位置
    vector<int> dp(32);
    dp[0]=2, dp[1]=3;
    for(int i=2;i<32;i++) 
        dp[i]=dp[i-1] + dp[i-2];
    int bitCount = 0;
    while((n>>bitCount)>0) ++bitCount;
    --bitCount; // 因为位是从0开始数，所以需要在减一
    // 最好是能够遇到两个相连的1，这样便于计算
    // 判断是否有相邻的1，相邻的0
    int result = dp[bitCount-1]; // 最高位为0时存在的可能数量
    int count0=0, count1=1; // 因为当前最高位一定为1，所以1有一个
    for(int i=bitCount-1;i>=0;--i) {
        if((n>>i)&1) { // 当前位为1
            cout << i << " " << (n>>i) << " " << " count: " << count1<<endl;
            ++count1;
            if(count1==1) {
                if(i>0) result+=dp[i-1];
                else result+=1;
            }
            else if(count1==2){
                if(i>0) result+=dp[i-1];
                else result+=1;
                return result;
            }
        } 
        else { // 当前位为0
            count1=0;
        }
    }
    return result+1; // 还包含最后一位取0的结果，1种可能
}

int main() {
    cout << "result: " << findIntegers(10)<<endl;
    return 0;
}