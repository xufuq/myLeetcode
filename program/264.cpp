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

int nthUglyNumber(int n) {
    if(n == 1) return 1;
    priority_queue<int, vector<int>, greater<int>>lessQue;
    unordered_set<int> visited;
    lessQue.push(1);
    visited.insert(1);
    int count = 0;
    while(count<n-1) {
        ++count;
        int cur=lessQue.top();
        lessQue.pop();
        if(visited.count(cur*2) ==0) {
            visited.insert(cur*2);
            lessQue.push(2*cur);
        }
        if(visited.count(cur*3) ==0) {
            visited.insert(cur*3);
            lessQue.push(3*cur);
        }
        if(visited.count(cur*5) ==0) {
            visited.insert(cur*5);
            lessQue.push(5*cur);
        }
    }
    return lessQue.top();
}