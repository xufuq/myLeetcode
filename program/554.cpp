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

// 找出每一行的砖缝就可以了
// 统计哪个砖缝最多
// 不能从墙的左右边界穿过
int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int ,int> mp;
    int result = 0;
    for(auto &w : wall) {
        int sum = 0;
        for(int i = 0; i < w.size()-1;++i) {
            sum+=w[i];
            ++mp[sum];
            result=max(result, mp[sum]);
        }
    }
    return wall.size()-result;
}