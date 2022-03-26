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

bool isBadVersion(int version);

int firstBadVersion(int n) {
    int start=1, end=n, mid=start+(end-start)/2;
    while(end-start!=0) {
        if(isBadVersion(mid)) 
            end=mid;
        else
            start=mid+1;
        mid=start+(end-start)/2;
    }
    return start;
}