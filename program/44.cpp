#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

// 这种类型的题不能被数组迷惑，要时钟记得是在考虑当前两个字符串在下标下的对比
// 不要往回推太多，否则容易陷入混乱
bool isMatch(string s, string p) {
    int sLen=s.length(), pLen=p.length();
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));
    dp[0][0]=true;
    for(int j=0;j<pLen&&p[j]=='*';++j)
        dp[0][j+1]=true;
    for(int i=1; i<=sLen; i++){
        for(int j=1; j<=pLen; j++){
            if((s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1])
                dp[i][j]=true;
            else if(p[j-1]=='*')
                dp[i][j]=dp[i][j-1]||dp[i-1][j]; // 不用当前*，即把它当成空字符串
        }
    }
    return dp[sLen][pLen];
}