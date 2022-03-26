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

int findSubstringInWraproundString(string p) {
    vector<int> charMaxLen(26, 0);
    int result = 0, start = 0;
    charMaxLen[p[0]-'a']=1;
    ++result;
    for(int i=1; i<p.length(); ++i) {
        if(p[i]-p[i-1]!=1 && p[i-1]-p[i]!=25) 
            start = i;
        if(i-start+1>charMaxLen[p[i]-'a']){ // 有新出现的子字符串
            result+=i-start+1-charMaxLen[p[i]-'a'];
            charMaxLen[p[i]-'a']=i-start+1;
        }
    }
    return result;
}