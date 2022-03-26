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

// 先验证b是不是按照a 的顺序排列的
int repeatedStringMatch(string a, string b) {
    int bFirstStartInA=0, aLen=a.length(), bLen=b.length();
    while(bFirstStartInA<aLen) {
        if(a[bFirstStartInA]!=b[0]) ++bFirstStartInA;
        else {
            int i=1;
            for(;i<bLen;++i) {
                if(a[(bFirstStartInA+i)%aLen]!=b[i]) {
                    ++bFirstStartInA;
                    break;
                }
            }
            if(i==bLen) break;
        }
    }
    if(bFirstStartInA==aLen) return -1;
    int result;
    if(bFirstStartInA==0) {
        result=bLen/aLen;
        if(bLen%aLen) ++result;
    } else {
        int aFirstStartInB=aLen-bFirstStartInA;
        result=((bLen-aFirstStartInB)/aLen)+1+(bLen-aFirstStartInB)%aLen==0;
    }
    return result;
}

// 可以用长串找子串的方法strstr,只有b/a，b/a+1,b/a+2这三个数可能是正确答案
// 也可以用KMP的方法，要回顾一下
