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

int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int result = INT_MAX;
    for(int i = 1; i < timePoints.size();++i) {
        int preH=stoi(timePoints[i-1].substr(0, 2));
        int preM=stoi(timePoints[i-1].substr(3, 2));
        int curH=stoi(timePoints[i].substr(0, 2));
        int curM=stoi(timePoints[i].substr(3, 2));
        result=min(result, (curH-preH)*60+curM-preM);
    }
    int preH=stoi(timePoints[0].substr(0, 2));
    int preM=stoi(timePoints[0].substr(3, 2));
    int curH=stoi(timePoints[timePoints.size()-1].substr(0, 2));
    int curM=stoi(timePoints[timePoints.size()-1].substr(3, 2));
    int ht=(curH-preH)*60+curM-preM;
    result=min(result, min(24*60-ht, ht));
    return result;
}