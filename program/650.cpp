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

// 寻找当前的最小因数
int minSteps(int n) {
    int result = 0;
    while(n!=1) {
        for(int i=2; i <= n;++i) {
            if(n%i==0) {
                result+=n/i-1;
                n/=i;
                break;
            }
        }
    }
    return result;
}