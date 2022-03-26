#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


// 暴力破解法
bool repeatedSubstringPattern(string s) {
    int i=0, len = 1, slength = s.length();
    while(len<=slength/2){
        string str = s.substr(i, len);
        i += len;
        while(i+len<=slength){
            if(s.compare(i, len, str)) // 不相等
                break;
            else if(i+len==slength)
                return true;
            i += len;
        }
        ++len;
        i=0;
    }
    return false;
}

// KMP方法
// 找到最后一个-1，小于一半的字符串长度
// 且总长度要是这个位置的整数倍
bool repeatedSubstringPattern1(string s) {
    int slen = s.length();

    vector<int> next(slen);
    int j=-1;
    next[0] = -1;
    for(int i=1; i<slen;++i){
        while(j>0 && s[i]!=s[j+1])
            j = next[j];
        if(s[i]==s[j+1])
            ++j;
        next[i]=j;
    }
    int maxLen = next[slen-1];
    if(maxLen!=-1 && (maxLen+1)%(slen-maxLen-1)==0)
        return true;
    return false;
}

// 还有一种方法是把两个s结合在一起，然后从第二个字符开始搜索，如果有子串说明是符合条件的

int main (){
    string s = "abaababaababaab";
    cout << repeatedSubstringPattern1(s) << endl;
}