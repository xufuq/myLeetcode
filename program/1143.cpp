#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    // dp是到当前位置为止的公共子序列，与当前
    vector<vector<int> > dp(text1.length()+1, vector<int>(text2.length()+1,0)); // 多一个空间方便循环
    for(int i=1;i<=text1.length();++i){
        for(int j=1;j<=text2.length();++j){
            if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[text1.length()][text2.length()];
}