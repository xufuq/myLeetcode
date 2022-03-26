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

int addDigits(int num) {
    int result = 0;
    while(num>9) {
        while(num>0) {
            result += num%10;
            num/=10;
        }
        num=result;
        result=0;
    }
    return num;
}