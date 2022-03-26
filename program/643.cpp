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
#include <time.h>
using namespace std;


double findMaxAverage(vector<int>& nums, int k) {
    int sum=accumulate(nums.begin(), nums.begin()+k, 0), maxSum=sum;
    for(int i=1;i<=nums.size()-k;i++) {
        sum+=nums[i+k-1]-nums[i-1];
        maxSum=max(sum,maxSum);
    }
    return maxSum*1.0/k;
}