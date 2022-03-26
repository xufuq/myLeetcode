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

char findTheDifference(string s, string t) {
    unordered_map<char, int> mp;
    for(auto &c : s) ++mp[c];
    for(auto &c : t) {
        if(mp.count(c)) --mp[c];
        else return c;
    }
    return ' ';
}