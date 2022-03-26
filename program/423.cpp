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

string originalDigits(string s) {
    string result;
    vector<int> countChars(26), countNum(10);
    for(auto &c : s) ++countChars[c-'a'];
    // 6 six
    countNum[6]=countChars['x'-'a'];
    countChars['s'-'a']-=countNum[6];
    // 7 seven
    countNum[7]=countChars['s'-'a'];
    countChars['e'-'a']-=2*countNum[7];
    // 0 zero
    countNum[0]=countChars['z'-'a'];
    countChars['e'-'a']-=countNum[0];
    countChars['r'-'a']-=countNum[0];
    countChars['o'-'a']-=countNum[0];
    // 2 two
    countNum[2]=countChars['w'-'a'];
    countChars['o'-'a']-=countNum[2];
    // 4 four
    countNum[4]=countChars['u'-'a'];
    countChars['o'-'a']-=countNum[4];
    countChars['r'-'a']-=countNum[4];
    countChars['f'-'a']-=countNum[4];
    // 1 one
    countNum[1]=countChars['o'-'a'];
    countChars['e'-'a']-=countNum[1];
    // 3 three
    countNum[3]=countChars['r'-'a'];
    countChars['e'-'a']-=2*countNum[3];
    // 8 eight
    countNum[8]=countChars['g'-'a'];
    countChars['e'-'a']-=countNum[8];
    // 5 five
    countNum[5]=countChars['f'-'a'];
    countChars['e'-'a']-=countNum[5];
    // 9 nine
    countNum[9]=countChars['e'-'a'];

    for(int i=0;i<10;++i) 
        result+=string(countNum[i], i+'0');
    return result;
}