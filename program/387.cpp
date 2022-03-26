#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> mp;
    for(auto &c : s) 
        ++mp[c];
    for(int i=0;i<s.length();++i) 
        if(mp[s[i]]<2) return i;
    return -1;
}