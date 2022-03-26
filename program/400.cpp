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

int findNthDigit(int n) {
    if(n<10) return n;
    unsigned long base=9;
    int count=1, cur=0;
    while(n>base*count) {
        n-=base*count;
        cur=(cur+1)*10-1;
        ++count;
        base*=10;
    }
    if(n%count==0) 
        return (cur+n/count)%10;
    cur=cur+n/count+1;
    int a=count-n%count;
    while(a>0) {
        cur/=10;
        --a;
    }
    return cur%10;
}