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
#include <queue>
using namespace std;

int minMutation(string start, string end, unordered_map<string, bool> &bankMap, unordered_map<int, int> &changedMap) {
    int result = INT_MAX;
    for(auto &mp:changedMap) {
        
    }
}


// 用map记录是否存在及是否使用，bank里面的
// 用另一个map记录需要改变的位置，并记录是否被改过
int minMutation(string start, string end, vector<string>& bank) {
    unordered_map<string, bool> bankMap;
    unordered_map<int, int> changedMap;
    for(int i=0;i<start.length();++i) {
        if(start[i]!=end[i]) {
            if(start[i]=='A')
                changedMap[i] |= 1;
            else if(start[i]=='C')
                changedMap[i] |= 1<<1;
            else if(start[i]=='G')
                changedMap[i] |= 1<<2;
            else if(start[i]=='T')
                changedMap[i] |= 1<<3;
        }
    }
    for(auto &str:bank)
        bankMap[str]=true;

    return minMutation(start, end, bankMap, changedMap);
}