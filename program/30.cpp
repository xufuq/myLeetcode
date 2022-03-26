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
#include <time.h>
using namespace std;

// 一个重要的前提是单词的长度相同
// 所以不用考虑某一个单词是另外一个单词的前缀这样的问题
// 哈希表复制浪费时间，还是按照原来的方式好
vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> wCount, wCount2;
    for(auto &word : words) 
        ++wCount[word];
    vector<int> result;
    int wordLen=words[0].length(), totalLen=wordLen*words.size(), sLen=s.length();
    for(int i=0;i<wordLen;++i) {
        string str;
        wCount2=wCount;
        int left=i, right=i, count=wCount2.size();// count代表的是未匹配的单词的个数(重复的算一个)
        while(right<=sLen-wordLen) {
            str=s.substr(right, wordLen);
            if(wCount2.count(str)) { // 数组中出现过这个单词
                --wCount2[str];
                if(wCount2[str]==0)        --count; // 刚好匹配
                else if(wCount2[str]==-1)  ++count; // 匹配多了
                right+=wordLen;
            }
            else { // 不包含这个序列，那么这一段都不能要了
                wCount2=wCount, count=wCount2.size();
                left=right+wordLen;
                right=left;
            }
            if(right-left==totalLen) {
                if(count==0) result.push_back(left);
                str=s.substr(left, wordLen);
                ++wCount2[str];
                if(wCount2[str]==0)       --count;
                else if(wCount2[str]==1)  ++count;
                left+=wordLen;
            }
        }
    }
    return result;
}