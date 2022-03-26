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

bool wordPattern(string pattern, string s) {
    string word;
    unordered_map<string, char> mp;
    vector<int> visited(26,0);
    int i=0;
    stringstream is(s);
    while(is>>word) {
        if(mp[word]==0) {
            mp[word]=pattern[i];
            ++visited[pattern[i]-'a'];
            if(visited[pattern[i]-'a']==2)
                return false;
        }
        else if(mp[word]!=pattern[i])
            return false;
        ++i;
    }
    if(i!=pattern.length()) return false;
    return true;
}