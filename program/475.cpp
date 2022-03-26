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
#include <time.h>
using namespace std;

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end()); //
    int result = INT_MIN;
    int heatersIndex = 0;
    for(int i=0; i<houses.size(); i++) {
        while(heatersIndex<heaters.size()-1 && houses[i]>=heaters[heatersIndex+1])
            ++heatersIndex;
        int curMin = INT_MAX, j=heatersIndex;
        for(;j<heaters.size() && heaters[j]<=houses[i];++j) 
            curMin=min(curMin, abs(heaters[j]-houses[i]));
        if(j!=heaters.size())
            curMin=min(curMin, abs(heaters[j]-houses[i]));
        result=max(result, curMin);
    }
    return result;
}