#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

int maxProduct(vector<int>& nums) {
    int n=nums.size(), result=INT_MIN;
    for(int i=0; i<n;++i){
        int cur=1;
        for(int j=i; j<n;++j){
            cur*=nums[j];
            if(cur>result) result=cur;
        }
    }
    return result;
}

// 官方解法
// max动归
int maxProduct(vector<int>& nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int mx = maxF, mn = minF;  // 其实就是因为负号引起的最大最小问题，其中一个一定是从头乘到尾的
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}
