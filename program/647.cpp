#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int countSubstrings(string s) {
    int len = s.length();
    // dp记录当前是否是回文串
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    int result = 0; // 记录当前有多少组回文串
    for(int i = 0; i < len;++i){
        dp[i][i]=true;
        ++result;
    }
    for(int i = len-1; i>=0; --i){
        for(int j = i+1; j < len; ++j){
            if(s[i]==s[j]){
                if(j-i<2 || dp[i+1][j-1]) {
                    dp[i][j]=true;
                    ++result;
                }
            }
            else
                dp[i][j]=false;
        }
    }
    return result;
}

// 双指针法做起来也不错