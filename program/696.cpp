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

// 同一个子串中的0和1必须相邻
int countBinarySubstrings(string s) {
    bool cur0_1=false;
    int count0=0, count1=0, start0=0, start1=0, result=0;
    for(int i=0; i<s.length();++i) {
        if(s[i] == '0') {
            if(!cur0_1) { // 上一个也是0
                ++count0;
                if(count1>=count0) ++result;
            } else { // 上一个是1,0第一次出现或者不连续
                count0=1;
                ++result;
                cur0_1=false;
            }
        } else { // 出现的是1
            if(!cur0_1) { // 上一个出现的是0
                cur0_1=true;
                count1=1;
                ++result;
            } else { // 上一个也是1
                ++count1;
                if(count0>=count1) ++result;
            }
        }
    }
    return result;
}

// 官方题解是按照01的连续数组分段