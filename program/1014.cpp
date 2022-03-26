#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

// 实时更新左侧的最大值
// 并且依次和最右侧的值相结合
int maxScoreSightseeingPair(vector<int>& values) {
    int n=values.size(), ans=0, mx=values[0]+0;
    for(int i=1;i<n;++i) {
        ans=max(ans, mx+values[i]-i);
        mx=max(mx, values[i]+i);
    }
    return ans;
}