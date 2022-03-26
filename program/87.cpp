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

// 分而治之
// 有两种情况，一个是不反转，一个是翻转
// 这两种情况需要分别考虑，暂时还没有想好要怎么做
bool isScramble(string &s1, string &s2, int sIndex, int eIndex) {
    if(s1.compare(sIndex, eIndex-sIndex, s2, sIndex, eIndex-sIndex)==0) return true; // 两个子字符串相等，自然满足条件
    vector<int> sCount1(26, 0), sCount2(26, 0);
    for(int i=sIndex; i<eIndex-1;++i) {
        ++sCount1[s1[i]-'a'];
        ++sCount2[s2[i]-'a'];
        if(sCount1==sCount2 && isScramble(s1, s2, sIndex, i+1) && isScramble(s1, s2, i+1, eIndex)) 
            return true;
    }
    return false;
}

bool isScramble(string s1, string s2) {
    return isScramble(s1, s2, 0, s1.length());
}  