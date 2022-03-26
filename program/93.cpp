#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> result;

// 判断当前数字是否合法
bool isAvailable(string &s, int start, int end){
    if(end-start>1 && s[start]=='0') return false; // 不能有前导0
    int num=0;
    for(int i=start;i<end;++i)
        num=num*10+s[i]-'0';
    if(num>255) return false; //
    return true;
}

void restoreIpAddresses(string &s, int start, vector<string> &IP){
    if(start==s.length() && IP.size()==7){ // 长度为7才是有效信号
        string str;
        for(auto s : IP)
            str+=s;
        result.push_back(str);
    }
    for(int i=1; i<=3 && i<=s.length()-start && IP.size()<7; ++i){ // IP一段长度最大为3
        if(isAvailable(s, start, start+i)){// str是合法的
            if(!IP.empty()) IP.push_back(".");
            IP.push_back(s.substr(start, i));
            restoreIpAddresses(s, start+i, IP);
            IP.pop_back();
            if(!IP.empty()) IP.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> IP;
    restoreIpAddresses(s, 0, IP);
    return result;
}