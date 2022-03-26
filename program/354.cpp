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

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end());
    vector<int> cur=envelopes[0];
    int result=1;
    for(auto &v:envelopes) {
        if(cur[0]<v[0] && cur[1]<v[1]) {
            ++result;
            cur=v;
        }
    }
    return result;
}