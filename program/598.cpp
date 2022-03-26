#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
#include <numeric>
using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int height=m, width=n;
    for(auto &point : ops) {
        height=min(height, point[0]);
        width=min(width, point[1]);
    }
    return height*width;
}