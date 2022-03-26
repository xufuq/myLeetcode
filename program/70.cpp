#include <vector>

using namespace std;

// 第一步爬一部，那就对应n-1
// 第一步爬两阶，那就对应n-2
int climbStairs(int n) {
    if(n<3) return n;
    int first = 1, second=2, result=0;
    for(int i=3;i<=n;++i){
        result = first+second;
        first=second;
        second=result;
    }
    return result;
}