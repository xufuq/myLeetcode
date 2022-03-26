#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
using namespace std;

string decodeString(string s) {
    stack<int> st;
    for(int i = 0; i < s.length();++i) {
        if(s[i] == '[')
            st.push(i);
        else if(s[i] == ']') {
            int _start=st.top()-1; //找对应的数字
            while(_start>=0 && isdigit(s[_start])) _start--;
            ++_start;
            int count=stoi(s.substr(_start, st.top()-_start));
            string str=s.substr(st.top()+1, i-st.top()-1), back=s.substr(i+1, s.length()-i);
            s=s.substr(0, _start);
            while(count--)
                s+=str;
            s+=back;
            st.pop();
        }
    }
    return s;
}

// 官方题解是，数字一个栈，字母一个栈

int main(){
    string str="3[a]2[bc]";
    cout << decodeString(str);
}