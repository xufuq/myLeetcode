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

// 反向思考
// n-1个加一，就是1个每次减一，然后最后都减到和最想相等
int minMoves(vector<int>& nums) {
    if(nums.size()==1) return 0;
    int minNum=INT_MAX;
    for(int i = 0; i < nums.size();++i) 
        minNum = min(minNum, nums[i]);
    return accumulate(nums.begin(), nums.end(), 0)-minNum*nums.size();
}