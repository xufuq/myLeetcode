#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) { // 这里的k如果等于0就说明只能用当前路径了，不能再向下递归
    if(src==dst) return 0;
    else if(k<0) return -1; // 不能再选多余的航线了

    int minCost = -1, currentCost = 0;
    
    vector<int> canUsePath;
    // 航班不存在自环，可以不用考虑
    for(int i = 0; i < flights.size();++i){ // 有人用优先级队列，把花费小的放在前边
        if(flights[i][0]==src)
            canUsePath.push_back(i);
    }
    for(auto currentPath : canUsePath){
        currentCost += flights[currentPath][2];
        int leftCost = findCheapestPrice(n, flights, flights[currentPath][1], dst, k-1);
        if(leftCost!=-1 && minCost==-1)
            minCost=currentCost+leftCost;
        else if(leftCost!=-1 && minCost!=-1)
            minCost=min(currentCost+leftCost, minCost);
        currentCost-=flights[currentPath][2];
    }
    return minCost;
}

// 递归回溯法时间复杂度太高
// 试试用动态规划
// 这里看的是官方题解，数组下标没有想到可以这样
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int INF = 10000*101+1; // 不可能大过这个了
    vector<vector<int>> dp(k+2, vector<int>(n, INT_MAX)); // k+2表示坐几次飞机的下标，第二维是到达的目的地
    dp[0][src]=0;
    for(int i=1;i<=k+1;++i){ // i=k+1时就是恰好有k个中转站
        for(auto &flight : flights){
            int from=flight[0], to=flight[1], cost=flight[2];
            dp[i][to]=min(dp[i][to], dp[i-1][from]+cost); // 在当前花费和从上一个地点到这来，比较那个最小，同时保证了满足k的条件
        }
    }
    int result=INF;
    for(int i=1;i<=k+1;++i){
        result=min(result, dp[i][dst]);
    }
    return result==INF?-1:result;
}