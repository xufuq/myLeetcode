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

bool judgeSquareSum(int c) {
    if(c<3) return true;
    unordered_map<int, int> mp;
    for(int i=0; i*i<=c;++i) 
        mp[i]=i*i;
    cout << "--------------------------------" <<mp[2] << endl;
    for(int i=1;mp[i]<=c;++i) {
        cout << "i" << endl;
        for(int j=0;mp[j]<=c;++j) {
            // cout << mp[j] << " ";
            if(mp[i]+mp[j]==c) return true;
            else if(mp[i]+mp[j]>c) break;
        }
    }
    return false;
}

// 双指针从两段向中间靠近

int main() {
    cout << judgeSquareSum(5);
}