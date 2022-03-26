#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

// 对开始点进行排序

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    vector<vector<int>> result;
    for(auto vec : points) {
        if(result.empty()) result.push_back(vec);
        else if(result.back()[1] >= vec[0]){ // 有重叠部分
            result.back()[0]=vec[0]; // 因为已经排过序了, vec[0]肯定相对较大
            result.back()[1]=min(result.back()[1],vec[1]);
        }
        else // 没有重叠
            result.push_back(vec);
    }
    return result.size();
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int startIndex, endIndex, count;
    for(auto vec : points) {
        if(count!=0 && endIndex >= vec[0]){ // 有重叠部分
            startIndex=vec[0]; // 因为已经排过序了, vec[0]肯定相对较大
            endIndex=min(endIndex,vec[1]);
        }
        else{  // 没有重叠
            startIndex= vec[0];
            endIndex=vec[1];
            ++count;
        }
    }
    return count;
}
