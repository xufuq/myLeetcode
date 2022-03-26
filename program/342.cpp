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

bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    while(n>1) {
        if(n%4==0) n/=4;
        else return false;
    }
    return true;
}