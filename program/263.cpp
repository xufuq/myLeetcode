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

bool isUgly(int n) {
    if(n<=0) return false;
    while(n>1) {
        if(n%2==0)      n=n/2;
        else if(n%3==0) n=n/3;
        else if(n%5==0) n=n/5;
        else return false;
    }
    return true;
}