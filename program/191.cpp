#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
using namespace std;

int hammingWeight(uint32_t n) {
    int result=0;
    while(n>0) {
        result+=n&1;
        n>>1;
    }
    return result;
}