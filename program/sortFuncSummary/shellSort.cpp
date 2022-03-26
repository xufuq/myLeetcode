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

void shellSort(vector<int> &nums, int gap, int i) {
    int curNum=nums[i];
    for(;i>=gap && curNum<nums[i-gap];i-=gap) {
        nums[i]=nums[i-gap];
    }
    nums[i]=curNum;
}

void shellSort(vector<int> &nums) {
    int N=nums.size();
    for(int Gap=N/2; Gap>0;Gap/=2) {
        // 不是单独先处理某一个组
        // 而是依次处理序列中的每一个元素
        // 通过加减Gap就能保证对应的元素在对应的组
        for(int i=Gap; i<N; ++i) { // 每一组的第一个默认是排序好的，因为就一个元素
            shellSort(nums, Gap, i);
        }
    }
}