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

int countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    if(n>10) n=10;
    int result=10, cur=9, count=2, countN=1;
    while(count<=n) {
        while(countN<count) {
            cur*=10-countN;
            ++countN;
        }
        result+=cur;
        cur=9;
        countN=1;
        ++count;
    }
    return result;
}