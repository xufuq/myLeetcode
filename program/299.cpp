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

// 先找公牛再找母牛
string getHint(string secret, string guess) {
    vector<int> sCount(10), gCount(26);
    int sameCount = 0;
    for(int i=0;i<secret.length();i++) {
        if(secret[i]==guess[i]) ++sameCount;
        else {
            ++sCount[secret[i]-'0'];
            ++gCount[guess[i]-'0'];
        }
    }
    string result=to_string(sameCount)+"A";
    sameCount=0;
    for(int i=0;i<10;++i)
        sameCount+=min(sCount[i], gCount[i]);
    result+=to_string(sameCount)+"B";
    return result;
}