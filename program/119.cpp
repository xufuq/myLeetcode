#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
#include <numeric>
using namespace std;

vector<int> getRow(int rowIndex) {
    if(rowIndex==0) return vector<int>{1};
    vector<vector<int>> dp(2, vector<int>(rowIndex+1));
    dp[0][0]=1; // 第一行
    dp[1][0]=1, dp[1][1]=1;
    for(int i=2;i<=rowIndex;i++) {
        dp[i%2][0]=1, dp[i%2][i]=1;
        for(int j=1;j<i;j++) 
            dp[i%2][j]=dp[(i+1)%2][j-1]+dp[(i+1)%2][j];
    }
    return dp[rowIndex%2];
}