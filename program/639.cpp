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

// 动态规划求解
int numDecodings(string s) {
    if(s[0]=='0') return 0;
    int len = s.length();
    vector<long> dp(len+1);
    dp[0]=1;
    if(isdigit(s[0])) dp[1]=1;
    else dp[1]=9;
    for(int i=1;i<len;++i) {
        if(s[i]=='0') {
            if(s[i-1]=='*')
                dp[i+1]=dp[i-1]*2;
            else if(s[i-1]=='0' || s[i-1]>'2')
                return 0;
            else
                dp[i+1]=dp[i-1];
        }
        else if(isdigit(s[i])) { // 是数字0以外的数字
            if(s[i-1]=='0')  // 上一个元素也是数字
                dp[i+1]=dp[i];
            else if(s[i-1]=='1') 
                dp[i+1]=dp[i]+dp[i-1];
            else if(s[i-1]=='2') {
                if(s[i]>'6')
                    dp[i+1]=dp[i];
                else
                    dp[i+1]=dp[i]+dp[i-1];
            }
            else if(isdigit(s[i-1])) // 大于2的数字
                dp[i+1]=dp[i];
            else { // 上一个元素是*
                if(s[i]>'6')
                    dp[i+1]=dp[i]+dp[i-1];
                else
                    dp[i+1]=dp[i]+dp[i-1]*2;
            }
        }
        else { //当前元素是*
            if(s[i-1]=='*')  // 连着两个*
                dp[i+1]=dp[i]*9+dp[i-1]*15;
            else if(s[i-1]=='0' || s[i-1]>'2')
                dp[i+1]=9*dp[i];
            else if(s[i-1]=='1')
                dp[i+1]=dp[i]*9+dp[i-1]*9;
            else if(s[i-1]=='2')
                dp[i+1]=dp[i]*9+dp[i-1]*6;
        }
        dp[i+1]%=1000000007;
    }
    return dp.back();
}

// 简化dp数组，dp有三个元素就够了，需要一直叫唤
int numDecodings(string s) {
    if(s[0]=='0') return 0;
    int len = s.length();
    vector<long> dp(len+1);
    dp[0]=1;
    if(isdigit(s[0])) dp[1]=1;
    else dp[1]=9;
    for(int i=1;i<len;++i) {
        if(s[i]=='0') {
            if(s[i-1]=='*')
                dp[i+1]=dp[i-1]*2;
            else if(s[i-1]=='0' || s[i-1]>'2')
                return 0;
            else
                dp[i+1]=dp[i-1];
        }
        else if(isdigit(s[i])) { // 是数字0以外的数字
            if(s[i-1]=='0')  // 上一个元素也是数字
                dp[i+1]=dp[i];
            else if(s[i-1]=='1') 
                dp[i+1]=dp[i]+dp[i-1];
            else if(s[i-1]=='2') {
                if(s[i]>'6')
                    dp[i+1]=dp[i];
                else
                    dp[i+1]=dp[i]+dp[i-1];
            }
            else if(isdigit(s[i-1])) // 大于2的数字
                dp[i+1]=dp[i];
            else { // 上一个元素是*
                if(s[i]>'6')
                    dp[i+1]=dp[i]+dp[i-1];
                else
                    dp[i+1]=dp[i]+dp[i-1]*2;
            }
        }
        else { //当前元素是*
            if(s[i-1]=='*')  // 连着两个*
                dp[i+1]=dp[i]*9+dp[i-1]*15;
            else if(s[i-1]=='0' || s[i-1]>'2')
                dp[i+1]=9*dp[i];
            else if(s[i-1]=='1')
                dp[i+1]=dp[i]*9+dp[i-1]*9;
            else if(s[i-1]=='2')
                dp[i+1]=dp[i]*9+dp[i-1]*6;
        }
        dp[i+1]%=1000000007;
    }
    return dp.back();
}