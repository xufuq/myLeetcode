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

vector<int> getTime(int n, int totalLed, int maxNum) {
    if(n==0 ) {
        if(totalLed>=0)
            return vector<int>{0};
        else 
            return vector<int>();
    }
    vector<int> result;
    for(int i=0;i<=totalLed-n;i++) {
        int base=pow(2, i);
        vector<int> back=getTime(n-1, totalLed-i-1, maxNum);
        for(auto &b:back) {
            if(base+base*2*b<maxNum)
                result.push_back(base+base*2*b);
        }
    }
    return result;
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> result;
    for(int i = 0; i <= min(turnedOn, 3);++i) {
        vector<int> hour=getTime(i, 4, 12);
        if(turnedOn-i>6) continue;
        vector<int> minute=getTime(turnedOn-i, 6, 60);
        string str;
        for(auto &h:hour) {
            for(auto &m:minute){
                str=to_string(h)+":";
                if(m<10) str+="0"; 
                str+=to_string(m);
                result.push_back(str);
            }
        }
    }
    return result;
}
int main() {
    vector<string> result=readBinaryWatch(9);
    for(auto &str:result)
        cout << str << endl;
}