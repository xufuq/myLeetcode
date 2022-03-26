#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// 先算出总面积在计算重复面积
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int result = abs(ax2-ax1)*abs(ay2-ay1) + abs(by2-by1)*abs(bx1-bx2);
    int x3=max(ax1, bx1), y3=max(ay1, by1);
    int x4=min(ax2, bx2), y4=min(ay2, by2);
    if(x3<x4 && y3<y4)
        result-=abs(x3-x4)*abs(y3-y4);
    return result;
}   