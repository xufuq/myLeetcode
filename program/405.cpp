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

string toHex(int num) {
    if(num==0) return "0";
    vector<string> nums={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
    unsigned int src=(unsigned int)num;
    string result;
    while(src>0) {
        result=nums[src&15]+result;
        src>>=4;
    }
    return result;
}

int main() {
    cout << toHex(-1);
}