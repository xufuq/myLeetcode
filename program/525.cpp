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

// 遇到0减一
// 遇到1加一
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0]=-1;
    int count = 0, result = 0;
    for(int i = 0; i < nums.size();++i) {
        if(nums[i] == 0) --count;
        else             ++count;
        if(mp.count(count)) result = max(result, i-mp[count]);
        else mp[count] = i;
    }
    return result;
}