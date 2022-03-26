#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    int length = s.length();
    int startIndex = 0, strLen=1;
    vector<vector<int>> dp(length, vector<int>(length, 0));
    for(int i=0;i<length;++i) // 最斜边一斜
        dp[i][i]=1;

    for(int i=length-2;i>=0;--i){
        for(int j=i+1;j<length;++j){
            if(s[i]==s[j] && dp[i+1][j-1]>=0){
                dp[i][j]=dp[i+1][j-1]+2;
                if(strLen<dp[i][j]){
                    startIndex=i;
                    strLen=dp[i][j];
                }
            }
            else
                dp[i][j]=-1;
        }
    }
    return s.substr(startIndex, strLen);
}