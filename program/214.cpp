#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

bool isPalid(string &s, int endIndex) {
    int startIndex = 0;
    while(startIndex < endIndex) {
        if(s[startIndex] != s[endIndex])
            return false;
    }
    return true;
}

// 找到当前s从头开始的最长回文串
// 时间复杂度超了
string shortestPalindrome(string s) {
    // 动态规划找最长回文串
    int sLen=s.length(), maxLength=1;
    vector<vector<bool>> dp;
    for(int i=0;i<sLen;++i) dp[i][i]=true;
    for(int i=sLen-2;i>=0;--i) {
        for(int j=i+1;j<sLen-1;--j) {
            if(j==i+1 && s[i]==s[j]) dp[i][j]=true;
            else if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            if(i==0 && dp[i][j]) {
                maxLength=j+1;
                break;
            }
        }
    }
    string str=s.substr(maxLength, s.length()-maxLength);
    reverse(str.begin(), str.end());
    return str+s;
}