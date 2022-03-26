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

string predictPartyVictory(string senate) {
    int n=senate.size(), rCount = 0, dCount = 0, rToReset = 0, dToReset = 0;
    vector<bool> rVec(n), dVec(n);
    for(int i=0;i<n;++i) {
        if(senate[i]=='R') {
            ++rCount;
            rVec[i]=true;
            dVec[i]=false;
        } else {
            ++dCount;
            rVec[i]=false;
            dVec[i]=true;
        }
    }
    int index=0;
    while(rCount!=0 && dCount!=0) {
        if(senate[index]=='R' && rVec[index]) {
            if(rToReset>0){
                --rToReset;
                rVec[index]=false;
            }
            else{
                ++dToReset;
                --dCount;
            }
                
        } else if(senate[index]=='D' && dVec[index]) {
            if(dToReset>0) {
                --dToReset;
                dVec[index]=false;
            }
            else {
                ++rToReset;
                --rCount;
            }
        }
        ++index;
        index%=n;
    }
    if(dCount==0) return "Radiant";
    else          return "Dire";
}