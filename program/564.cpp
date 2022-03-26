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

// 不对
string nearestPalindromic(string n) {
    bool isPalid=true;
    int left=0, right=n.length()-1, nLen=n.length();
    while(left<right) {
        if(n[left]!=n[right]) {
            n[right]=n[left];
            isPalid=false;
        }
    }
    if(isPalid) {
        if(nLen%2==0) { // 中间数有两个
            if(n[nLen/2]=='0') {
                n[nLen/2-1]='1';
                n[nLen/2]='1';
            } else {
                n[nLen/2]=n[nLen/2]-1;
                n[nLen/2-1]=n[nLen/2]-1;
            }
        } else {
            if(n[nLen/2]=='0') 
                n[nLen/2]='1';
            else 
                n[nLen/2]=n[nLen/2]-1;
        }
    }
    return n;
}