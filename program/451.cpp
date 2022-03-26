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

static bool compare(const vector<int>& Lhs, const vector<int>& Rhs) {
    return Lhs[1]>Rhs[1];
}

string frequencySort(string s) {
    vector<vector<int>> charCounts(52, vector<int>(2,0));
    for(int i=0;i<52;++i) charCounts[i][0]=i;
    for(auto &c : s) {
        if(islower(c)) ++charCounts[c-'a'][1];
        else           ++charCounts[c-'A'+26][1];
    }
    sort(charCounts.begin(), charCounts.end(), compare);
    string res;
    for(int i=0;i<52;++i) {
        if(charCounts[i][1]==0) return res;
        res+=string(charCounts[i][1], charCounts[i][0]<26?charCounts[i][0]+'a':charCounts[i][0]+'A');
    }
    return res;
}

int main() {
    cout << frequencySort("abcc");
}