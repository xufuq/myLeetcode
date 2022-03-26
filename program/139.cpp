#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <functional>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.length();
    // 下标n表示到当前坐标为止，这个字符串是否可以用字典中的字符串组成
    vector<bool> dp(s.length()+1, false);
    dp[0]=true;
    for(int i=1;i<=len;++i){
        for(auto str : wordDict){
            if(str.length() <= i){ // 长度符合要求
                int startIndex = i - str.length();
                if(!s.compare(startIndex, str.length(), str) && dp[startIndex]) { //可以匹配
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    return dp[len];
}