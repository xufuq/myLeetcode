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

void selectSort(vector<int> &nums) {
    for(int i=0;i<nums.size();i++) {
        int minIndex=i;
        for(int j=i;j<nums.size();j++) {
            if(nums[j]<nums[minIndex])
                minIndex=j;
        }
        swap(nums[i], nums[minIndex]);
    }
}