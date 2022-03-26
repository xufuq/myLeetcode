#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

// 先排序
// 有重复就留结尾靠前的，删除结尾靠后的

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());
    int endIndex=intervals[0][1], count=0, len = intervals.size();
    for(int i=1;i<len;++i) {
        if(endIndex>intervals[i][0]) { // 有重合
            endIndex=min(endIndex, intervals[i][1]);
            ++count;
        }
        else
            endIndex=intervals[i][1];
    }
    return count;
}