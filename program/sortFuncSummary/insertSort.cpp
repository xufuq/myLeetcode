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

void insertSort(vector<int> &nums, int curIndex) {
    int curNum=nums[curIndex];
    for(;curIndex>0 && nums[curIndex-1]>curNum;--curIndex) {
        nums[curIndex]=nums[curIndex-1];
    }
    nums[curIndex]=curNum;
}

void insertSort(vector<int> &nums) {
    // 0位置本来就是有序的
    for(int i=1;i<nums.size();i++) 
        insertSort(nums, i);
}