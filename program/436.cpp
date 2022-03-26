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

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n=intervals.size();
    vector<vector<int>> sortedVec;
    for(auto vec:intervals) {
        vec.push_back(sortedVec.size());
        sortedVec.push_back(vec);
    }
    sort(sortedVec.begin(), sortedVec.end());
    vector<int> result(n);
    for(int i=0;i<n;++i) {
        int start=0, end=n-1, mid=(start+end)/2, curIndex=-1;
        while(start<=end) {
            if(sortedVec[mid][0]==intervals[i][1]) {
                curIndex=sortedVec[mid][2];
                break;
            }
            else if(sortedVec[mid][0]>intervals[i][1]) {
                if(curIndex==-1 || intervals[curIndex][0]>sortedVec[mid][0])
                    curIndex=sortedVec[mid][2];
                end=mid-1;
            }
            else
                start=mid+1;
            mid=(start+end)/2;
        }
        result[i]=curIndex;
    }
    return result;
}