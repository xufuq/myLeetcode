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

// 这个队列的方法做起来太麻烦，判断条件过多，考虑双指针的做法
string findLongestWord(string s, vector<string>& dictionary) {
    int curLength = 0, sLen=s.length();
    string result;
    vector<queue<int>> schar(26), sChar(26);
    for(int i = 0; i < s.length(); ++i) 
        schar[s[i]-'a'].push(i);
    for(auto &word : dictionary) {
        if(word.length()<=sLen && word.length()>curLength) {
            sChar=schar;
            int curSIndex=0;
            for(int i=0;i<word.length(); ++i) {
                if(!sChar[word[i]-'a'].empty() && sLen-sChar[word[i]-'a'].front()>=word.length()-i && curSIndex<sChar[word[i]-'a'].front()) { // 可能满足条件
                    curSIndex=sChar[word[i]-'a'].front();
                    sChar[word[i]-'a'].pop();
                    if(i==word.length()-1) {
                        curLength=word.length();
                        result=word;
                    }
                } else
                    break;
            }
        }
    }
    return result;
}

string findLongestWord(string s, vector<string>& dictionary) {
    sort(dictionary.begin(), dictionary.end());
    int curLength = 0, sLen=s.length();
    string result;
    for(auto &word : dictionary) {
        if(word.length()>curLength) {
            int wLIndex=0, sLIndex=0;
            while(sLIndex<sLen) {
                while(sLIndex<sLen && word[wLIndex]!=s[sLIndex]) ++sLIndex;
                if(sLIndex==sLen) break;
                else if(++wLIndex==word.length()) {
                    result=word;
                    curLength=word.length();
                }
                ++sLIndex;
            }
        }
    }
    return result;
}