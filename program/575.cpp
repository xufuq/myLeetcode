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

int distributeCandies(vector<int>& candyType) {
    // 先计算总的种类数
    unordered_set<int> typeCounts;
    for(auto &c:candyType)
        typeCounts.insert(c);
    if(typeCounts.size()>candyType.size()/2) return candyType.size()/2;
    else return typeCounts.size();
}   