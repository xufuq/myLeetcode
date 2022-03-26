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

// 依然是滑动窗口，或者叫双指针，因为窗口大小不定
// 一个数组记录当前窗口中出现的字符的次数,一个变量记录出现的最多的字符的次数
// 两个变量记录左右节点，一个变量记录找到的最大的长度
int getMaxValue(vector<int> &sCount) {
    int maxValue=0;
    for(auto &n:sCount)
        maxValue=max(maxValue, n);
    return maxValue;
}

int characterReplacement(string s, int k) {
    int len=s.length();
    if(len<=k+1) return len;
    vector<int> sCount(26);
    int maxLen=k, mostCharCount=0, indexL=0, indexR=k;
    for(int i=0;i<=k;++i) {
        ++sCount[s[i]-'A'];
       mostCharCount=max(mostCharCount, sCount[s[i]-'A']);
    }
    while(indexR<len) {
        while(indexR-indexL+1 - mostCharCount>k) {
            --sCount[s[indexL]-'A'];
            mostCharCount=getMaxValue(sCount);
            ++indexL;
        }
        while(indexR-indexL+1 - mostCharCount<=k) { // 等于k的时候就会退出循环，即可以求出当前子串的长度
            ++indexR;
            if(indexR==len) break;
            ++sCount[s[indexR]-'A'];
            mostCharCount=max(mostCharCount, sCount[s[indexR]-'A']);
        }
        maxLen=max(maxLen, indexR-indexL);
    }
    
    return maxLen;
}