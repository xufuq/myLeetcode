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
#include <time.h>
using namespace std;

string removeKdigits(string num, int k) {
    while(k>0) {
        if(num.length()<=k) return "0";
        if(num[0]<=num[1]) {
            int i=1;
            while(i<num.length() && num[i+1]>=num[i]) 
                ++i;
            if(i==num.length() || num[i]<num[0])
                num.erase(num.begin(), num.begin()+1);
            else
                num.erase(num.begin()+i, num.begin()+1+i);
        }
        else {
            num.erase(num.begin(), num.begin()+1);
            int i=0;
            while(i<num.length() && num[i]=='0')
                ++i;
            num.erase(num.begin(), num.begin()+i);
        }
        --k;
    }
    return num.empty()?"0":num;
}