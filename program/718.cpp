#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;

// 也可以将数组的大小在两个维度各扩充1，这样就不用了单独初始化两条边界了
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int aLen = nums1.size(), bLen = nums2.size(), result = 0;
    // 数组代表的含义是如果这两个元素不相等，则对应为0
    // 如果这两个元素相等，那么位置的值就表示，包括这两个元素在内，他之前的元素有几对匹配的
    vector<vector<int>> dp(aLen, vector<int>(bLen, 0));
    // 先初始化两条边界
    for(int i=0; i<aLen;++i)
        if(nums1[i]==nums2[0]) dp[i][0]=1;
    for(int i=1;i<bLen;++i)
        if(nums2[i]==nums1[0]) dp[0][i]=1;

    for(int i=1;i<aLen;++i){
        for(int j=1;j<bLen;++j){
            if(nums1[i]==nums2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else if(dp[i-1][j-1]>result) result = dp[i-1][j-1];
        }
    }
    if(dp[aLen-1][bLen-1]>result) result = dp[aLen-1][bLen-1];
    return result;
}

// 一维数组的，不太好理解，官方题解
int findLength(vector<int>& A, vector<int>& B) {
    vector<int> dp(vector<int>(B.size() + 1, 0));
    int result = 0;
    for (int i = 1; i <= A.size(); i++) {
        for (int j = B.size(); j > 0; j--) {
            if (A[i - 1] == B[j - 1]) {
                dp[j] = dp[j - 1] + 1; // 这里是避免重复覆盖，因为用的是上一个循环的内容，避免在用之前已经被覆盖
            } else dp[j] = 0; // 注意这里不相等的时候要有赋0的操作
            if (dp[j] > result) result = dp[j];
        }
    }
    return result;
}