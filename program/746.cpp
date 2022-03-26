#include <vector>
#include <algorithm>

using namespace std; 

int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();
    int first=0, second=0, result=0; // 开始可以免费上到第一个或者第二个
    for(int i=2;i<=len;++i){
        result = min(first + cost[i-2], second + cost[i-1]);
        first=second;
        second=result;
    }
    return result;
}