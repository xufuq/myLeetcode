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

bool judgeCircle(string moves) {
    unordered_map<char, int> countChar;
    for(auto &c : moves) 
        ++countChar[c];

    if(countChar['L']==countChar['R'] && countChar['U']==countChar['D']) return true;
    return false;
}