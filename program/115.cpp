#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int numDistinct(string s, string t) {
    int sLen = s.length(), tLen = t.length();
    // 在当前的s[0-i]这段字符子串中
    // t在当前的t[0-j]范围内有多少种可行的组合
    // 这个题目力扣描述反了
    vector<vector<unsigned int>> dp(tLen+1, vector<unsigned int>(sLen+1, 0));
    for(int i = 0; i <= sLen; i++) {
        dp[0][i]=1;
    }
    for(int i = 1; i <= tLen; ++i){
        for(int j = 1; j <= sLen; ++j){
            if(t[i-1]==s[j-1]) dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
            else dp[i][j]=dp[i][j-1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[tLen][sLen];
}

int main(){
    string s = "babgbag", t = "bag";
    // string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s,t);
}