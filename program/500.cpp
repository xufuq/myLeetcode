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

vector<string> findWords(vector<string>& words) {
    string line="qwertyuiop";
    unordered_map<char, int> mp;
    for(auto &c: line) 
        mp[c] = 1;
    line="asdfghjkl";
    for(auto &c: line) 
        mp[c] = 2;
    line="zxcvbnm";
    for(auto &c: line) 
        mp[c] = 3;
    vector<string> result;
    for(auto &str : words) {
        int s=mp[str[0]];
        bool isSame=true;
        for(auto &c : str) {
            if(s!=mp[c]) {
                isSame=false;
                break;
            }
        }
        if(isSame)
            result.push_back(str);
    }
    return result;
}