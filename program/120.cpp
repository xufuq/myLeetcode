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

int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size(), flag = 0;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0]=triangle.back();
    for(int i=triangle.size()-2; i>=0;--i) { // 最后一行已经处理过了
        for(int j=0; j<=i; j++) {
            dp[(flag+1)%2][j]=min(dp[flag][j], dp[flag][j+1])+triangle[i][j];
            flag=(flag+1)%2;
        }
    }
    return dp[0][0];
}