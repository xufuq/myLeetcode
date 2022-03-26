#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "math.h"
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> cmap;
    int maxCount=0, maxnumber=0;
    for(auto &c : tasks) 
        ++cmap[c];
    for(auto p : cmap){
        if(maxCount==p.second)
            ++maxnumber;
        else if(maxCount<p.second){
            maxCount=p.second;
            maxnumber=1;
        }
    }
    return max((maxCount-1)*(n+1)+maxnumber, (int)tasks.size());
}