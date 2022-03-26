#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool checkValidString(string s) {
    stack<int> st, star;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(')
            st.push(s[i]);
        else if(s[i]=='*')
            star.push(s[i]);
        else if(s[i]==')') {
            if(!st.empty())
                st.pop();
            else if(!star.empty())
                star.pop();
            else
                return false;
        }
    } 
    while(!st.empty()) {// 还有左括号剩余
        if(!star.empty() && star.top()>st.top())
            st.pop(), star.pop();
        else
            return false;
    }
    return true;
}