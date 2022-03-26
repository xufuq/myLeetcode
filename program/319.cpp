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

// 其实就是统计每个1-n的数有多少个因数
// 单个因数亮，双数因数不亮
// 有单个因数只可能是因为其能够开方
int bulbSwitch(int n) {
    int result=0, base=1;
    while(base*base<=n) {
        ++result;
        ++base;
    }
    return result;
}