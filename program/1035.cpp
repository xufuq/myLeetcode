#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

// 用递归思路很清晰
// 分为相等和不相等两种情况
// 所以用dp来做

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    // dp记录从起点到当前坐标最多可以重合多少个
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            if(nums1[i-1]==nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[len1][len2];
}