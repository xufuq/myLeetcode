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

string convertToTitle(int columnNumber) {
    string result;
    while(columnNumber>0) {
        result=string(1, ('A'+(columnNumber-1)%26))+result;
        if(columnNumber==26) break;
        if(columnNumber%26==0) columnNumber=columnNumber/26-1;
        else                   columnNumber/=26;
    }
    return result;
}