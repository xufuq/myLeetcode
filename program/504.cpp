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

string convertToBase7(int num) {
    if(num == 0) return "0";
    string result;
    while(num!=0) {
        result+=to_string(num%7);
        num /= 7;
    }
    return result;
}