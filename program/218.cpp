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
using namespace std;

// 官方题解使用优先级队列做的
vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    map<int, int> xToy;
    xToy[-1]=0; // 作为最后一个，便于比较
    for(auto build : buildings) {
        auto begin=xToy.find(build[0]), end=xToy.find(build[1]);

        if(end==xToy.end()) { // 没有当前元素，之前就有右边缘的话就不用改了
            xToy[build[1]]=0;
            end=xToy.find(build[1]);
            --end;
            xToy[build[1]]=end->second;
        }

        if(begin==xToy.end()) { // 没有当前元素
            xToy[build[0]]=0;
            begin=xToy.find(build[0]);
            --begin;
            xToy[build[0]]=max(build[2], begin->second);
        }
        else xToy[build[0]]=max(build[2], xToy[build[0]]);

        begin=xToy.find(build[0]), end=xToy.find(build[1]);
        while(begin != end) {
            (*begin).second=max(build[2], (*begin).second);
            ++begin;
        }
    }
    vector<vector<int>> result;
    for(auto &it : xToy) {
        if(result.empty())
            result.push_back({it.first, it.second});
        else if(it.second!=result.back()[1])
            result.push_back({it.first, it.second});
    }
    result.back()[1]=0;
    result.erase(result.begin());
    return result;
}
