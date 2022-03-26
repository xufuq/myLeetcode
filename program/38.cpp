#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

string lastStr="1";

string countAndSay(int n) {
    if(n==1) return lastStr;
    else {
        string str = lastStr;
        lastStr.clear();
        char ch = str[0];
        int count = 1;
        for(int i = 1; i < str.length(); i++) {
            if(str[i]==ch) ++count;
            else {
                lastStr=lastStr+to_string(count)+ch;
                ch=str[i];
                count=1;
            }
        }
        lastStr=lastStr+to_string(count)+ch;
        return countAndSay(n-1);
    }
}

// 迭代
string countAndSay(int n) {
    string lastStr="1";
    while(n>1){
        string str = lastStr;
        lastStr.clear();
        char ch = str[0];
        int count = 1;
        for(int i = 1; i < str.length(); i++) {
            if(str[i]==ch) ++count;
            else {
                lastStr=lastStr+to_string(count)+ch;
                ch=str[i];
                count=1;
            }
        }
        lastStr=lastStr+to_string(count)+ch;
        --n;
    }
    return lastStr;
}
