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

// 用一个辅助数组保存中间结果
// 避免一直动态分配内存
void merge(vector<int> &nums, vector<int> &temp, int left, int mid, int right) {
    int a=left, b=mid+1;
    for(int i=left; i<=right; i++) {
        if(a>mid) temp[i]=nums[b++];
        else if(b>right) temp[i]=nums[a++];
        else if(nums[a]<=nums[b]) temp[i]=nums[a++]; // 这里的<=号保证了稳定性
        else      temp[i]=nums[b++];
    }
    for(int i=left; i<=right; i++) 
        nums[i]=temp[i];
}

void mergeSort(vector<int> &nums, vector<int> &temp, int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSort(nums, temp, left, mid);
        mergeSort(nums, temp, mid+1, right);
        merge(nums, temp, left, mid, right);
    }
}

void mergeSort(vector<int> &nums) {
    vector<int> temp(nums.size());
    mergeSort(nums, temp, 0, nums.size()-1); // right是包含在需要排序的范围内的
}