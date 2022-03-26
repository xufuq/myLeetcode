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

string licenseKeyFormatting(string s, int k) {
    for(int i=s.length()-1; i>=0; --i) {
        if(s[i] == '-') s.replace(s.begin()+i, s.begin()+i+1, "");
        else if(isalpha(s[i])) s[i]=toupper(s[i]);
    }
    int len=s.length();
    for(int i=s.length()-k; i>0; i-=k) 
        s.insert(s.begin()+i, '-');
    return s;
}

int main() {
    cout << licenseKeyFormatting("2-5g-3-J", 2);
}