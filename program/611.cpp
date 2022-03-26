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

// 题解使用二分查找做的
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n=nums.size();
    int result = 0;
    for(int i=0;i<n;++i) {
        int k=i;
        for(int j=i+1;j<n;++j) { 
            while(k+1<n && nums[k]<nums[i]+nums[j]) // k作为最后一条边
                ++k;
            result+=max(k-j, 0);
        }
    }
    return result;
}