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
#include <queue>
using namespace std;

// 利用优先级队列
// 两个优先级队列实现
void wiggleSort(vector<int>& nums) {
    int len=nums.size(), maxNum=INT_MIN;
    unordered_map<int, int> numCount;
    for(auto &n:nums) {
        ++numCount[n];
        maxNum=max(maxNum,n);
    }
    priority_queue<vector<int>> firstQue, secondQue; // 默认是大根堆
    for(auto &mp:numCount)
        firstQue.push({mp.second, mp.first});
    // 先放好第一个，不能是最大的数
    vector<int> temp;
    if(firstQue.top()[1]!=maxNum) {
        nums[0]=firstQue.top()[1];
        temp=firstQue.top();
        firstQue.pop();
        --temp[0];
        firstQue.push(temp);
    }
    while(!firstQue.empty()) {

    }
}