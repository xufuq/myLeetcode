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

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int len=primes.size();
    vector<long> dp(n, INT_MAX);
    vector<long> index(len, 0), curNum(len);
    for(int i=0; i<len; i++) {
        curNum[i] = (long)primes[i];
    }
    vector<long> curIndex;
    dp[0] = 1;
    for(int i=1;i<=n;++i) {
        for(int j=0;j<len;++j) {
            if(dp[i]>curNum[j]) {
                curIndex.clear();
                dp[i]=curNum[j];
                curIndex.push_back(j);
            }
            else if(dp[i]==curNum[j])
                curIndex.push_back(j);
        }
        for(auto &x:curIndex) {
            ++index[x];
            curNum[x]=primes[x]*dp[index[x]];
        }
    }
    return dp[n];
}