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

bool checkPerfectNumber(int num) {
    if(num==1) return false;
    int left=2, right=num/2;
    int result = 1;
    while(left<=right) {
        if(left*right==num) {
            result+=left+right;
            if(left==right) result-=left;
        }
        ++left;
        right=num/left;
    }
    return result==num;
}