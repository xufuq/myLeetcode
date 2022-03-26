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

void getPermutation(string &str, vector<int> &count, int k) {
    if(k<2) return;
    int curIndex=1;
    while(count[curIndex]<k)
        ++curIndex;
    if(count[curIndex]==k) 
        reverse(str.begin()+str.length()-curIndex, str.end());
    else { // count[curIndex]>k
        int swapIndex=k/count[curIndex-1]-(k%count[curIndex-1]==0?1:0); // 不能让k变为0
        swap(str[str.length()-curIndex], str[str.length()-curIndex+swapIndex]);
        sort(str.begin()+str.length()-curIndex+1, str.end());
        k=k%count[curIndex-1]==0?count[curIndex-1]:k%count[curIndex-1]; // 不能让k变为0
        getPermutation(str, count, k);
    }
}

string getPermutation(int n, int k) {
    string str;
    vector<int> count(n+1);
    count[0]=1;
    for(int i=1;i<=n;++i) {
        str+=to_string(i);
        count[i]=i*count[i-1];
    }
    getPermutation(str, count, k);
    return str;
}