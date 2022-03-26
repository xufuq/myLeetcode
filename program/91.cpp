#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isDecode(string &s, int start, int end){
    if(s[start] =='0') return false;
    if(end == start) // 只有一个字符
        return true; //
    else if(end-start==1 && stoi(s.substr(start, 2))<=26)
        return true; //
    return false; //
}

int numDecodings(string s) {
    int len = s.length();
    vector<int> dp(len+1, 0);
    dp[0] = 1;
    if(isDecode(s, 0, 0)) dp[1]=1;
    for(int i=2;i<=len;++i){
        if(isDecode(s, i-1, i-1)) dp[i]+=dp[i-1];
        if(isDecode(s, i-2, i-1)) dp[i]+=dp[i-2];
    }
    return dp[len];
}