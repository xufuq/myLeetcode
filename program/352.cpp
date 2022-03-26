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

class SummaryRanges {
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        result.push_back(vector<int>());
        auto it = nums.begin(), end=nums.end();
        result.back().push_back(*it);
        result.back().push_back(*it);
        ++it;
        while(it != end) {
            if(*it==result.back()[1]+1)
                result.back()[1]+=1;
            else {
                result.push_back(vector<int>());
                result.back().push_back(*it);
                result.back().push_back(*it);
            }
            ++it;
        }
        return result;
    }
    set<int> nums;
};