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

// 必须是连续的，所以也是滑动窗口
bool checkInclusion(string s1, string s2) {
    if(s2.length()<s1.length()) return false;
    unordered_map<char, int> sCount(26);
    int count = s1.length(), len1=count;
    for(int i=0;i<s1.length();++i) 
        ++sCount[s1[i]];
    for(int i=0;i<s1.length();++i) {
        if(sCount.count(s2[i])){
            --sCount[s2[i]];
            if(sCount[s2[i]]>=0)
                --count;
        }
    }
    if(count==0) return true;
    for(int i=1;i<=s2.length()-s1.length();++i) {
        if(sCount.count(s2[i-1])) {
            ++sCount[s2[i-1]];
            if(sCount[s2[i-1]]>0)
                ++count;
        }
        if(sCount.count(s2[i+len1-1])) {
            --sCount[s2[i+len1-1]];
            if(sCount[s2[i+len1-1]]>=0)
                --count;
        }
        if(count==0) return true;
    }
    return false;
}