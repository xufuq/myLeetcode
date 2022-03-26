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

bool setStr(vector<string> &vec, int &curIndex) {
    if(curIndex>=vec.size()) return false;
    if(vec[curIndex]=="#") {
        ++curIndex;
        return true;
    }
    ++curIndex; // 看左节点
    if(!setStr(vec, curIndex)) return false;
    if(!setStr(vec, curIndex)) return false;
    return true;
}

bool isValidSerialization(string preorder) {
    vector<string> vec;
    stringstream is(preorder);
    string str;
    while(getline(is, str, ',')) 
        vec.push_back(str);
    int index=0;
    if(!setStr(vec, index)) return false;
    if(index<vec.size()) return false;
    return true;
}  