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

// 用两个哈希表维护
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> mp1, mp2;
    for(int i=0; i<list1.size(); i++) 
        mp1[list1[i]] = i;
    for(int i=0; i<list2.size(); i++) 
        mp2[list2[i]] = i;
    unordered_set<string> result;
    int curMin=INT_MAX;
    for(int i=0; i<list1.size(); i++) {
        int curCount;
        if(mp2.count(list1[i]))
            curCount=mp2[list1[i]]+i;
        else
            curCount=10000+i;
        if(curCount<curMin) {
            result.clear();
            result.insert(list1[i]);
            curMin=curCount;
        } else if(curCount==curMin)
            result.insert(list1[i]);
    }
    for(int i=0; i<list2.size(); i++) {
        int curCount;
        if(mp1.count(list2[i]))
            curCount=mp1[list2[i]]+i;
        else
            curCount=10000+i;
        if(curCount<curMin) {
            result.clear();
            result.insert(list2[i]);
            curMin=curCount;
        } else if(curCount==curMin)
            result.insert(list2[i]);
    }
    return vector<string>(result.begin(), result.end());
}