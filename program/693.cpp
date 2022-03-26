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

bool hasAlternatingBits(int n) {
    while(n>0) {
        if((n&1)==((n>>1)&1)) return false;
        n>>=1;
    }
    return true;
}