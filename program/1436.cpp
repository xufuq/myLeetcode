#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
#include <queue>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_set<string> sNames;
    for(auto &s:paths) 
        sNames.insert(s[0]);
    for(auto &s:paths){
        if(sNames.count(s[1])==0)
            return s[1];
    }
    return paths[0][1];
}   