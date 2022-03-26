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

void bubbleSort(vector<int> &nums) {
    if(nums.size()<2) return;
    for(int i=0;i<nums.size();i++) {
        bool flag = false;
        for(int j=0;j<nums.size()-i-1;j++) {
            if(nums[j]>nums[j+1]) {
                swap(nums[j],nums[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}