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
using namespace std;

int calculate(string s) {
    stack<char> alpha;
    stack<int> num;
    for(int i=0;i<s.length();) {
        if(s[i] == '-' || s[i] == '+') {
            if(!alpha.empty()) {
                int num2=num.top();
                num.pop();
                int num1=num.top();
                num.pop();
                // num.push(num1);
                char c=alpha.top();
                alpha.pop();
                if(c=='+')  
                    num.push(num1+num2);
                else
                    num.push(num1-num2);
            }
            alpha.push(s[i]);
            ++i;
        }
        else if(s[i]=='*' || s[i]=='/') 
            alpha.push(s[i++]);
        else if(isdigit(s[i])) {
            int nStart=i;
            while(i<s.length() && isdigit(s[i])) 
                ++i;
            int n=stoi(s.substr(nStart, i-nStart));
            if(!alpha.empty() && (alpha.top()=='*' || alpha.top()=='/')) {
                int num1=num.top();
                num.pop();
                if(alpha.top()=='*')
                    num.push(num1*n);
                else
                    num.push(num1/n);
                alpha.pop();
            }
            else 
                num.push(n);
        }
        else ++i;
    }
    if(!alpha.empty()) {
        int num2=num.top();
        num.pop();
        int num1=num.top();
        num.pop();
        // num.push(num1);
        char c=alpha.top();
        alpha.pop();
        if(c=='+')  
            num.push(num1+num2);
        else
            num.push(num1-num2);
    }
    return num.top();
}