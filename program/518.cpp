#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


// 在不超过总数的前提下尽可能大
// 数组的值表示当前的可能的组合数
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0]=1; // 为0的时候不用找，一种方式
    for(auto c : coins) {
        for(int i=c; i<=amount; ++i){
            dp[i] = dp[i] + dp[i-c];
        }
    }
    return dp[amount];
}