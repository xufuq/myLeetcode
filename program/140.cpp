#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

// vector<string> wordBreak(string s, vector<string>& wordDict) {
//     int len = s.length();
//     for(auto &s : wordDict) 
//         s.reserve(); // 字符串翻转，便于对比
//     sort(wordDict.begin(), wordDict.end());
//     vector<int> dp(len + 1, 0);
//     dp[0] =1;
//     for(int i=1; i<=len; ++i){
//         vector<int> count;
//     }
// }

vector<string> result;

void getString(string &s, vector<vector<int>> &dp, int start, string &lines){
    if(start==s.length()) {
        result.push_back(lines);
        return;
    }
    for(auto num : dp[start]){
        lines += s.substr(start, num);
        getString(s, dp, start+num, lines);
        lines.erase(lines.end()-num, lines.end());
    }
}

// 把字典放到哈希表中判断相等时直接count，很方便
vector<string> wordBreak(string s, vector<string>& wordDict) {
    int len = s.length();
    sort(wordDict.begin(), wordDict.end());
    vector<vector<int>> dp(len); // 存放从当前长度开始可以组成单词的长度
    for(int i=0; i<len;++i){
        for(int j=1;j<=s.length()-i;++j){
            bool equal = false;
            for(auto word : wordDict){
                if(s.compare(i, j, word, 0, j)){
                    if(s.compare(i, j, word))
                        dp[i].push_back(j);
                    else
                        equal=true;
                }
                if(!equal) break;
            }
        }
    }
    string line;
    getString(s, dp, 0, line);
    return result;
}