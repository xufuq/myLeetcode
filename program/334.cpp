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
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int count=0, curMin=INT_MAX, curMinSec=INT_MAX, curFirst=INT_MAX, curSec=INT_MAX;
    for(auto n : nums) {
        curMin=min(curMin, n);
        if(count==0) {
            curFirst=curMin;
            ++count;
        } else if (count==1) {
            if(n>curMinSec) return true;
            if(curFirst>n)
                curFirst=n;
            else if(curFirst<n) {
                curSec=n;
                ++count;
            }
        } else if(count==2) {
            if(n>curSec) return true;
            else if(n>curFirst && n < curSec) curSec=n;
            else if(n<curFirst) {
                curMinSec=curSec;
                curFirst=curMin;
                count=1;
            }
        }
    }
    return false;
}