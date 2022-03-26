#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSubsequence(string s, string t) {
    int i=0, len = s.length();
    if(len==0) return true;
    for(auto c : t){
        if(s[i]==c) 
            ++i;
        if(i==len) return true;
    }
    return false;
}