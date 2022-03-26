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

int findComplement(int num) {
    int base=1;
    while(base<num) 
        base=(base<<1) + 1;
    return base-num;
}