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

// 给定的位置坐标是有石子的地方
// 用当前更新以后，而不是以后访问从前
bool canCross(vector<int>& stones, int ) {

}

bool canCross(vector<int>& stones) {
    if(stones[1]!=1) return false;
    unordered_map<int, unordered_set<int>> posVec;
    for(auto &s:stones) 
        posVec[s].insert(-1);
    posVec[stones[1]].clear();
    posVec[stones[1]].insert(1);
    for(int i=1;i<stones.size();++i) {
        for(auto &n: posVec[stones[i]]) {
            if(n==-1) 
                break;
            else {
                if(posVec.count(stones[i]+n)) {
                    if(posVec[stones[i]+n].count(-1)) 
                        posVec[stones[i]+n].clear();
                    posVec[stones[i]+n].insert(n);
                }
                if(posVec.count(stones[i]+n+1)) {
                    if(posVec[stones[i]+n+1].count(-1)) 
                        posVec[stones[i]+n+1].clear();
                    posVec[stones[i]+n+1].insert(n+1);
                }
                if(posVec.count(stones[i]+n-1)) {
                    if(posVec[stones[i]+n-1].count(-1)) 
                        posVec[stones[i]+n-1].clear();
                    posVec[stones[i]+n-1].insert(n-1);
                }
            }
        }
    }
    if(posVec[stones.back()].count(-1))
        return false;
    return true;
}