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

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> visitedNums;
    for(auto num : nums) {
        if(visitedNums.count(num)) return true;
        else visitedNums.insert(num);
    }
    return false;
}