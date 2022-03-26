#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
#include <queue>
using namespace std;

bool isPalid(string &s, int sIndex, int eIndex) {
    while(sIndex<eIndex) {
        if(s[sIndex]!=s[eIndex]) return false;
        ++sIndex;
        --eIndex;
    }
    return true;
}

bool validPalindrome(string s) {
    int left=0, right=s.length()-1;
    bool isChanged = false;
    while(left<right) {
        if(s[left]!=s[right]) {
            if(isPalid(s, left+1, right)) return true;
            else if(isPalid(s, left, right-1)) return true;
            else return false;
        }
        else {
            ++left;
            --right;
        }
    }
    return true;
}