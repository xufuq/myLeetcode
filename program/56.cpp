#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()<2) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for(auto vec : intervals){
        if(result.back()[1]>=vec[0]) // 可以连在一起
            result.back()[1]=max(result.back()[1], vec[1]);
        else // 不连，各种数据更新
            result.push_back(vec);

    }

    return result;
}