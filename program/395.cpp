#include <map>
#include <set>
#include <queue>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 分而治之
int longestSubstring(string &s, int startIndex, int endIndex, unordered_map<char, int> &totalMp, const int &k) {
    unordered_map<char, int> curMp;
    int result=0, curLackK=0;
    for(int i=startIndex;i<endIndex;++i) {
        if(totalMp[s[i]]<k) { // 当前字符肯定不能构成答案
            if(i==startIndex) startIndex+=1;// 重新定位开始位置，没有必要进行下一步递归
            else {
                for(auto &m : curMp)
                    totalMp[m.first]-=m.second;
                result=max(result, longestSubstring(s, startIndex, i, curMp, k));
                startIndex=i+1;
                curMp.clear();
                curLackK=0;
            }
        } else {
            ++curMp[s[i]];
            if(curMp[s[i]]==1) ++curLackK;
            else if(curMp[s[i]]==k) --curLackK;
            if(curLackK==0) result=max(result, i-startIndex+1);
        }
    }
    return result;
}   

int longestSubstring(string s, int k) {
    unordered_map<char, int> totalMp;
    for(auto &c : s) 
        ++totalMp[c];
    if(k==1) return s.length();
    return longestSubstring(s, 0, s.length(), totalMp, k);
}

int main(){
    string str="bbaaacbd";
    cout << longestSubstring(str, 3);
}