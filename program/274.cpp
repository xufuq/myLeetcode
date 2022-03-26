#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    if(citations[0]==0) return 0;
    int h=0;
    for(int i = 0; i < citations.size();++i) {
        if(citations[i]==0) h=max(h, min(citations[i-1], i));
        else h=max(h, min(citations[i], i+1));
    }
    return h;
}