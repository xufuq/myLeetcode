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

int integerReplacement(int n) {
    if(n==1) return 0;
    else if(n%2==0) 
        return integerReplacement(n/2)+1;
    else if(n==INT_MAX)
        return 32;
    else // 必定是奇数
        return min(integerReplacement(n-1), integerReplacement(n+1))+1;
}