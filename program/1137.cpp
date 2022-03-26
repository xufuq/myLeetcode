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

int tribonacci(int n) {
    switch (n) {
    case 0: 
        return 0;
    case 1: 
        return 1;
    case 2: 
        return 1;
    default:
        break;
    }
    vector<int> dp(n+1);
    dp[0] =0, dp[1]=1, dp[2]=1;
    for(int i=3; i<=n; i++) 
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    return dp[n];
}