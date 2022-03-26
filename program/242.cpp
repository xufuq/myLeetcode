// 用数组
#include "string"
using namespace std;

bool isAnagram(string s, string t) {
    int sarray[26] = {0}, tarray[26]={0};
    for(auto c :s)
        ++sarray[c-'a'];
    for(auto c :t)
        ++tarray[c-'a'];
    for(int i=0; i<26;++i) {
        if(sarray[i]!=tarray[i])
            return false;
    }
    return true;
}