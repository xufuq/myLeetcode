#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>
#include "math.h"
using namespace std;

// 这个感觉需要用记忆话搜索
// 超时，用简单方法
// int findLongestChain(vector<vector<int>>& pairs, vector<unordered_map<int, int>> &dp, int index, int tail) {
//     if(index>=dp.size()) return 0;
//     int result = 0;
//     if(tail<pairs[index][0]) {  // 不冲突，可以用
//         if(dp[index].count(tail)==0)
//             dp[index][tail]=max(findLongestChain(pairs, dp, index+1, pairs[index][1])+1, findLongestChain(pairs, dp, index+1, tail));
//         result=dp[index][tail];
//     }
//     else { // 尾冲突
//         if(dp[index].count(tail)==0)
//             dp[index][tail]=findLongestChain(pairs, dp, index+1, tail);
//         result=dp[index][tail];
//     }
//     return result;
// }

// int findLongestChain(vector<vector<int>>& pairs) {
//     sort(pairs.begin(), pairs.end());
//     int n=pairs.size();
//     vector<unordered_map<int, int>> dp(n); // 从下标i开始最多有几个数对
//     return findLongestChain(pairs, dp, 0, INT_MIN);
// }

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end());
    vector<int> lastPair=pairs[0];
    int result=1;
    for(int i=1;i<pairs.size();i++) {
        if(pairs[i][0]<=lastPair[1]) { // 有交叉
            if(pairs[i][1]<=lastPair[1])
                lastPair=pairs[i];
        }
        else { // 没有交叉
            ++result;
            lastPair=pairs[i];
        }
    }
    return result;
}

int main() {

}