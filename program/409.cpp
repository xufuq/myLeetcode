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

int longestPalindrome(string s) {
    unordered_map<char, int> mp;
    for(auto &c : s) 
        ++mp[c];
    int result=0, aExists = 0;
    for(auto &m : mp) {
        if(m.second%2==1) {
            aExists=1;
            result+=m.second-1;
        }
        else
            result+=m.second;
    }
    return result+aExists;
}