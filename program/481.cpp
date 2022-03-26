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

int magicalString(int n) {
    if(n<=3) return 1;
    string magicStr="122";
    int index=2, count=1;
    while(magicStr.length()<n) {
        if(magicStr[index]=='2') {
            if(magicStr.back()=='1') magicStr+="22";
            else                     magicStr+="11", count+=2;
        } else {
            if(magicStr.back()=='1') magicStr+="2";
            else                     magicStr+="1", count+=1;
        }
        ++index;
    }
    if(magicStr.length()>n && magicStr.back()=='1') --count;
    return count;
}
