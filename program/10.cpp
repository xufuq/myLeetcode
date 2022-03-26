#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 时间复杂度太高，超出时间限制
// bool isMatch(string s, string p, int sStart, int pStart) {
//     if(pStart==p.length() && sStart!=s.length()) return false;
//     else if(pStart==p.length() && sStart==s.length()) return true;
//     else if(sStart==s.length()){ // 判断p剩下的是否可以化为0
//         for(int i=pStart; i<p.length();++i){
//             if(p[i]!='*'){
//                 if(i==s.length()-1) return false;
//                 else if(p[i+1]!='*') return false;
//             }
//         }
//         // 可以化为空字符串
//         return true;
//     }
//     if(s[sStart]==p[pStart] || p[pStart]=='.'){ 
//         if(pStart==p.length()-1) return isMatch(s, p, sStart+1, pStart+1);
//         else if(p[pStart+1]=='*') return isMatch(s, p, sStart+1, pStart+1) || isMatch(s, p, sStart, pStart+2);
//         else return isMatch(s, p, sStart+1, pStart+1);
//     }
//     else if(p[pStart]=='*'){
//         if(pStart>0 && (p[pStart-1]=='.' || p[pStart-1]==s[sStart])) return isMatch(s, p, sStart+1, pStart) || isMatch(s, p, sStart, pStart+1);
//         else return isMatch(s, p, sStart, pStart+1);
//     }
//     else{
//         if(pStart<p.length()-1 && p[pStart+1]=='*') return isMatch(s, p, sStart, pStart+2);
//         else return false;
//     }
// }
// bool isMatch(string s, string p) {
//     return isMatch(s, p, 0, 0);
// }

// 用dp数组做
bool isMatch(string s, string p) {
    int sLen = s.length(), pLen = p.length();
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));
    dp[0][0]=true;
    for(int i=1; i<=sLen; ++i){
        for(int j=1;j<=pLen;++j){
            if(s[i-1]==p[j-1] || p[j-1]=='.'){ // 这里是匹配上了
                dp[i][j]=dp[i-1][j-1];
            }
            else if(p[j-1]=='*') { // 关键是这个地方的处理
                if(s[i-1]==p[j-2] || p[j-2]=='.'){ // 前一个字符匹配上了
                    // dp[i][j]=dp[i-1][j-1] || dp[i-1][j] || dp[i][j-2]; // dp[i-1][j] 为真的话dp[i-1][j-1]肯定也为真,反过来也是一样,因为p[j-1]=='*'
                    dp[i][j]=dp[i-1][j] || dp[i][j-2]; // 这里的第一个条件还不是很清楚
                }
                else{
                    dp[i][j]=dp[i][j-2];
                }
            }
            else{
                dp[i][j]=false;
            }
        }
    }
    // 可以化为空字符串
    return dp[sLen][pLen];
}

int main(){
    string s="a", p="ab*";
    cout << isMatch(s,p) << endl;
}

// 官方题解
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) { 
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {// 这里判断是否匹配也考虑了i==0的情况，因为i==0也有可能匹配成功，即全都被*化为0消去
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 2]; // 这种情况是*取0，即把前面的符号给消去，看这样能否匹配
                    if (matches(i, j - 1)) { // s[i-1]==p[j-2]当前的s字符和p中*前面的字符匹配
                    // 这种情况是*取1或者更大，即把前面的字符重复，看这样能否匹配
                    // 从子字符串的角度来想，不要去数组里递推
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
 

// 自己手动实现以下
bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, false));
    dp[0][0] = true;
    for(int i = 1; i < m; i++) //当所有字符都被*消除的时候也可能符合条件，即s为空
        if(p[i-1]=='*') dp[0][i]=dp[0][i-2];
    for(int i = 1; i <= m; i++) {
        for(int j = 1;j<=n; ++j){
            if((s[i-1] == p[j-1] || p[j-1]=='.') && dp[i-1][j-1]) dp[i][j]=true;
            else if(p[j-1]=='*') {
                dp[i][j] |= dp[i][j-2];
                if((s[i-1] == p[j-2] || p[j-2]=='.'))
                    dp[i][j] |= dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}