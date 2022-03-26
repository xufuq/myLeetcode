#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "math.h"
using namespace std;

vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> pMap, sMap;
    int pCount = p.length(), curCount = 0, startIndex = 0;
    vector<int> result;
    for(auto c : p) 
        ++pMap[c]; //统计个数
    for(int i=0;i<s.length();++i){
        if(pMap[s[i]]==0) { // 不包括当前元素
            startIndex = i+1;
            sMap.clear();
            curCount=0;
            continue;
        }  
        // 包含当前元素
        ++sMap[s[i]];
        ++curCount;
        while(sMap[s[i]]>pMap[s[i]]){
            --sMap[s[startIndex]];
            ++startIndex;
            --curCount;
        }
        if(sMap[s[i]]<pMap[s[i]]) continue;
        if(curCount == pCount){
            result.push_back(startIndex);
            --sMap[s[startIndex]];
            ++startIndex;
            --curCount;
        }
    }
    return result;
}