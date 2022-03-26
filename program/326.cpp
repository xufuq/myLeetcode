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
using namespace std;

bool isPowerOfThree(int n) {
    if(n<=0) return false;
    while (n>1) {
        if(n%3) return false;
        n/=3;
    }
    return true;
}