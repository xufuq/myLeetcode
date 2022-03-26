#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0; // 剩余油量
    int length=gas.size();
    for(int i = 0; i < length; ++i) { // 起始站点
        for(int j=0; j < length; ++j) {
            int cur = (j+i)%length;
            sum += gas[cur]-cost[cur];
            if(sum < 0) break;
        }
        if(sum >= 0) return i;
    }
    return -1;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int length = gas.size();
    for(int i = 0; i < length; ++i)
        gas[i]=gas[i] - cost[i];
    if(accumulate(gas.begin(), gas.end(), 0)<0)  return -1;
    int sum=0, result=0;
    for(int i = 0; i < length; ++i){
        sum += gas[i];
        if(sum<0){
            sum=0;
            result=i+1;
        }
    }
    return result;
}