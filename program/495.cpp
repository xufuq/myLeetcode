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
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int result = 0;
    for(int i = 0; i < timeSeries.size()-1; i++) 
        result += min(duration, (timeSeries[i+1]-timeSeries[i]));
    result+=duration; // 最后一次攻击
    return result;
}