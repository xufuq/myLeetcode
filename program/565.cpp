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

// A不包含重复元素，所以每个环不会交叉
// 迭代也可以完成
// 或者是采用元素变为负数的方法，记录访问记录
int arrayNesting(vector<int>& nums, int nextIndex, vector<bool> &visited, int count) {
    if(visited[nextIndex]) return count;
    visited[nextIndex] = true;
    ++count;
    return arrayNesting(nums, nums[nextIndex], visited, count);
}

int arrayNesting(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    int result = 0;
    for(int i=0;i<nums.size();i++) 
        result=max(result, arrayNesting(nums, i, visited, 0));
    return result;
}