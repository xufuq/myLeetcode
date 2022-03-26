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

bool isPalindrome(string s) {
    int a=0, b=s.length()-1;
    while(a<b) {
        if(!isalnum(s[a])) {
            ++a;
            continue;
        }
        if(!isalnum(s[b])) {
            --b;
            continue;
        }
        if(isalpha(s[a]) && isalpha(s[b])) {
            if(tolower(s[a])==tolower(s[b])) 
                ++a, --b;
            else
                return false;
        }
        else {
            if(s[a]==s[b]) 
                ++a, --b;
            else 
                return false;
        }
    }
    return true;
}