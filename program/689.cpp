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

vector<int> getSorted(vector<int> &indexSum, int x, int y, int z) {
    vector<int> temp(3), result(3);
    temp[0] = indexSum[x], temp[1] = indexSum[y], temp[2] = indexSum[z];
    sort(temp.begin(), temp.end()); // 升序
    if(indexSum[x]==temp[0]) {
        result[2]=x;
        temp[0]=-1;
    }
    else if(indexSum[x]==temp[1]) {
        result[1]=x;
        temp[1]=-1;
    }
    else {
        result[0]=x;
        temp[2]=-1;
    }
    
    if(indexSum[y]==temp[0]) {
        result[2]=y;
        temp[0]=-1;
    }
    else if(indexSum[y]==temp[1]) {
        result[1]=y;
        temp[1]=-1;
    }
    else {
        result[0]=y;
        temp[2]=-1;
    }

    if(indexSum[z]==temp[0]) {
        result[2]=z;
        temp[0]=-1;
    }
    else if(indexSum[z]==temp[1]) {
        result[1]=z;
        temp[1]=-1;
    }
    else {
        result[0]=z;
        temp[2]=-1;
    }
    return result;
}

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int maxSum = 0, n=nums.size();
    vector<int> result(3), indexSum(n, 0), indexMaxSum(n);
    // dp数组中保存到当前为止最大的两个子数组
    // 以当前点作为结束点而不是开始的点
    vector<vector<int>> dp(n, vector<int>());
    indexSum[k-1]=accumulate(nums.begin(), nums.begin()+k, 0);
    dp[k-1].push_back(k-1);
    indexMaxSum[k-1]=k-1;
    for(int i=k;i<n;++i) {
        indexSum[i]=indexSum[i-1]-nums[i-k]+nums[i];
        indexMaxSum[i]=indexSum[indexMaxSum[i-1]]>=indexSum[i]?indexMaxSum[i-1]:i;
        if(i<2*k-1) { // 在这个范围内只能有一个完整数组
            if(indexSum[i]>indexSum[dp[i-1][0]])
                dp[i].push_back(i);
            else
                dp[i].push_back(dp[i-1][0]);
        }
        else if(i==2*k-1) {
            if(indexSum[k-1]>=indexSum[2*k-1]) {
                dp[i].push_back(k-1);
                dp[i].push_back(2*k-1);
            }
            else {
                dp[i].push_back(2*k-1);
                dp[i].push_back(k-1);
            }
        }
        else { // 在这个范围内只能有2个完整数组
            if(indexSum[i]+indexSum[indexMaxSum[i-k]]>indexSum[dp[i-1][0]]+indexSum[dp[i-1][1]]) {
                if(indexSum[indexMaxSum[i-k]]>=indexSum[i]) {
                    dp[i].push_back(indexMaxSum[i-k]);
                    dp[i].push_back(i);
                }
                else {
                    dp[i].push_back(i);
                    dp[i].push_back(indexMaxSum[i-k]);
                }
            }
            else
                dp[i]=dp[i-1];
            if(i>=3*k-1) {
                if(indexSum[i]+indexSum[dp[i-k][0]]+indexSum[dp[i-k][1]]>maxSum) {
                    maxSum=indexSum[i]+indexSum[dp[i-k][0]]+indexSum[dp[i-k][1]];
                    result=dp[i-k];
                    result.push_back(i);
                }
            }
        }
    }
    for(auto &d:result) 
        d-=k-1;
    sort(result.begin(), result.end());
    return result;
}  