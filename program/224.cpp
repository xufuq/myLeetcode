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

int calculate(stack<char> &signs, stack<int> &nums, int a){
    int b=0, result=0;
    if(!nums.empty()) {
        b=nums.top();
        nums.pop();
    }
    if(signs.top()=='+') 
        result=a+b;
    else
        result=b-a;
    signs.pop();
    return result;
}

int calculate(string s) {
    stack<int> nums;
    stack<char> signs;
    int last=0;//0 数字 1 加减号 2 左括号
    for(int i = 0; i <s.length();) {
        if(s[i] == ' ') ++i;
        else if(isdigit(s[i])) {
            int sIndex = i;
            while(i<s.length() && isdigit(s[i])) 
                ++i;
            int a=stoi(s.substr(sIndex, i-sIndex));
            if(signs.empty() || signs.top()=='(') 
                nums.push(a);
            else {
                a=calculate(signs, nums, a);
                nums.push(a);
            }
            last=0;
        }
        else {
            if(s[i]==')') {
                signs.pop(); // 弹出对应的左括号
                int a=nums.top();
                nums.pop();
                if(!signs.empty() && signs.top()!='(') 
                    a=calculate(signs, nums, a);
                nums.push(a);
            }
            else if(s[i]!='(') { //+-
                if(last==2)  // 之前出现的是左括号
                    nums.push(0);
                signs.push(s[i]);
                last=1;
            }
            else {
                last=2;
                signs.push(s[i]);
            }
                
            ++i;
        }
    }
    return nums.top();
}

// 官方题解很有意思