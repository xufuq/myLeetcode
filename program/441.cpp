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

int arrangeCoins(int n) {
    long start=1, end=n, mid=start+(end-start)/2;
    long result=mid*(mid+1)/2;
    while(start<end) {
        if(result==n)
            return mid;
        if((result-n>=0 && result-n<=mid))
            return mid-1;
        else if(n-result>=0 && n-result<mid+1)
            return mid;
        else if(result<n) 
            start=mid+1;
        else
            end=mid;
        mid=start+(end-start)/2;
        result=mid*(mid+1)/2;
    }
    return start;
}