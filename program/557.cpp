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

string reverseWords(string s) {
    int sIndex=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ') {
            reverse(s.begin()+sIndex, s.begin()+i);
            sIndex=i+1;
        }
    }
    return s;
}