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

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    bool newUsed=false;
    for(int i=0;i<intervals.size();) {    
        vector<int> vec;
        if(!newUsed && newInterval[0]<=intervals[i][0]) {
            vec=newInterval;
            newUsed=true;
        } 
        else
            vec=intervals[i++];
        if(result.empty() || vec[0]>result.back()[1])
            result.push_back(vec);
        else
            result.back()[1]=max(vec[1], result.back()[1]);
    }
    if(!newUsed) {
        if(result.empty() || newInterval[0]>result.back()[1])
            result.push_back(newInterval);
        else
            result.back()[1]=max(newInterval[1], result.back()[1]);
    }
    return result;
}