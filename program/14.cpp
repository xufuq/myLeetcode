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

string longestCommonPrefix(vector<string>& strs) {
    string result=strs[0];
    for(int i=1;i<strs.size();i++) {
        int minsize=min(result.length(), strs[i].length());
        int j=0;
        while( j<minsize && result[j]==strs[i][j]) {
            ++j;
        }
        result=result.substr(0,j);
    }
    return result;
}