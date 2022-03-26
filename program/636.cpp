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

vector<int> exclusiveTime(int n, vector<string>& logs) {
    stack<int> sTime; // 序号
    vector<int> result(n);
    int lastTime = 0;
    for(auto &str : logs) {
        int Lindex=0, Rindex=str.length()-1, index=-1, curTime=-1;
        while(isdigit(str[Lindex]))
            ++Lindex;
        index=stoi(str.substr(0, Lindex));
        while(isdigit(str[Rindex]))
            --Rindex;
        curTime=stoi(str.substr(Rindex+1, str.length()-1-Rindex));
        if(Rindex-Lindex==4) { // 结束  
            ++curTime; // 某一秒的开始
            result[index]+=curTime-lastTime;
            sTime.pop();
        }
        else { // 开始
            if(!sTime.empty()) { // 不为空
                result[sTime.top()]+=curTime-lastTime;
            }
            sTime.push(index);
        }
        lastTime=curTime;
    }
    return result;
}