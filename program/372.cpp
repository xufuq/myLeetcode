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

int superPow(int a, vector<int>& b) {
    int base=a%1337, result=1;
    for(auto it=b.rbegin(); it!=b.rend();++it) {
        a=base;
        for(int i=1;i<=*it;++it) {
            base*=a;
            base%=1337;
        }
        if(*it!=0) {
            result*=base;
            result%=1337;
        }
        for(int i=*it;i<10;++it)  {
            base*=a;
            base%=1337;
        }
    }
    return result;
}