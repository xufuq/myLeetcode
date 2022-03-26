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

int romanToInt(string s) {
    unordered_map<char, int> romanMap;
    romanMap['I']=1, romanMap['V']=5, romanMap['X']=10, romanMap['L']=50, romanMap['C']=100, romanMap['D']=500, romanMap['M']=1000;
    int result=romanMap[s[0]], last=result;
    for(int i=1; i<s.length(); ++i) {
        if(romanMap[s[i]]==last*5 || romanMap[s[i]]==last*10)
            result+=romanMap[s[i]]-last;
        else
            result+=romanMap[s[i]];
        last=romanMap[s[i]];
    }
    return result;
}