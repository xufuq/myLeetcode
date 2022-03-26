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
#include "math.h"
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        begin=nums.begin();
    }
    
    int sumRange(int left, int right) { 
        return accumulate(begin+left, begin+right+1, 0);
    }
private:
    vector<int>::iterator begin;
};