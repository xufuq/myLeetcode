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

// 用set做一下
// 感觉空间复杂度太高
vector<string> findRepeatedDnaSequences(string s) {
    int len = s.length();
    unordered_set<string> sequences, result;
    if(len<=10) return vector<string>();
    string str;
    for(int i=0; i<=len-10;++i) {
        str=s.substr(i, 10);
        if(sequences.count(str)) result.insert(str);
        else sequences.insert(str);
    }
    return vector<string>(result.begin(), result.end());
}

// 用KMP的方法应该可以
// KMP必须固定开头的元素，而此题的开头元素是随机的。