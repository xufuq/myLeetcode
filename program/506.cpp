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

vector<string> findRelativeRanks(vector<int>& score) {
    map<int, int, greater<int>> mp;
    for(int i=0; i<score.size(); i++) 
        mp[score[i]] = i;
    vector<string> result(score.size());
    int count = 0;
    for(auto &m : mp) {
        if(count==0) result[m.second]="Gold Medal";
        else if(count==1) result[m.second]="Silver Medal";
        else if(count==2) result[m.second]="Bronze Medal";
        else result[m.second]=to_string(count+1);
        ++count;
    }
    return result;
}