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

// 用堆栈实现
// 是否在压入时执行计算就是产生了括号的改变运算优先级的作用
// 这个方法不好，可以利用当前表达式的起止坐标来实现
// void diffWaysToCompute(string &expression, int index, stack<int> &numSt, stack<char> &signSt, vector<int> &result) {
//     if(index==expression.length()) { // 到达表达式 末尾
//         stack<int> numst = numSt;
//         stack<char> signst = signSt;
//         int cal=0;
//         while(!signst.empty()) {
//             int backnum=numst.top();
//             numst.pop();
//             int frontNum=numst.top();
//             numst.pop();
//             if(signst.top()=='+') 
//                 cal=frontNum+backnum;
//             else if(signst.top()=='-') 
//                 cal=frontNum-backnum;
//             else if(signst.top()=='*') 
//                 cal=frontNum*backnum;
//             signst.pop();
//             numst.push(cal);
//         }
//         result.push_back(numst.top());
//         return;
//     }
    
//     if(isdigit(expression[index])) { // 当前是数字
//         int sIndex=index;
//         while(isdigit(expression[index]))
//             ++index;
//         int num=stoi(expression.substr(sIndex, index-sIndex));
//         if(signSt.empty()) { // 没有运算符
//             numSt.push(num);
//             diffWaysToCompute(expression, index, numSt, signSt, result);
//             numSt.pop(); // 恢复现场
//         }
//         else { // 有运算符可以运算
//             int frontNum=numSt.top();
//             // 运算当前数字
//             numSt.pop(); //
//             int cal;
//             char s=signSt.top();
//             if(s=='+') 
//                 cal=frontNum+num;
//             else if(s=='-') 
//                 cal=frontNum-num;
//             else if(s=='*') 
//                 cal=frontNum*num;
//             signSt.pop(); //
//             numSt.push(cal);
//             diffWaysToCompute(expression, index, numSt, signSt, result);
//             signSt.push(s);
//             numSt.pop(); //
//             numSt.push(frontNum);
//             // 不运算
//             if(index!=expression.length()) { // 最后一个运算优先级会重复
//                 numSt.push(num);
//                 diffWaysToCompute(expression, index, numSt, signSt, result);
//                 numSt.pop(); //
//             }
            
//         }
//     }
//     else { // 当前是运算符
//         signSt.push(expression[index]);
//         ++index;
//         diffWaysToCompute(expression, index, numSt, signSt, result);
//         signSt.pop();
//     }
// }

// vector<int> diffWaysToCompute(string expression) {
//     stack<int> numSt;
//     numSt.push(0); // 放一个0方便后续运算
//     stack<char> signSt;
//     vector<int> result;
//     diffWaysToCompute(expression, 0, numSt, signSt, result);
//     return vector<int>(result.begin(), result.end());
// }

// 先假设其没有负数
vector<int> diffWaysToCompute(string &expression, int sIndex, int eIndex) {
    vector<int> result;
    // 先找到第一个数
    int i=sIndex;
    while(i<eIndex && isdigit(expression[i]))
        ++i;
    int num=stoi(expression.substr(sIndex, i-sIndex));
    if(i==eIndex) // 只有这一个数字
        return vector<int>{num};
    else {
        vector<int> right=diffWaysToCompute(expression, i+1, eIndex);
        for(auto &R:right) {
            if(expression[i]=='+')
                result.push_back(num+R);
            else if(expression[i]=='-')
                result.push_back(num-R);
            else
                result.push_back(num*R);
        }
    }
    ++i; // 令其指向下一个数字
    while(i<eIndex) { // 不能包括头尾，否则会有重复结果
        while(i<eIndex && isdigit(expression[i]))
            ++i;
        // 当前的i位置是符号
        if(i<eIndex) { // 有有效优先级
            vector<int> left=diffWaysToCompute(expression, sIndex, i);
            vector<int> right=diffWaysToCompute(expression, i+1, eIndex);
            for(auto &L:left) {
                for(auto &R:right) {
                    if(expression[i]=='+')
                        result.push_back(L+R);
                    else if(expression[i]=='-')
                        result.push_back(L-R);
                    else
                        result.push_back(L*R);
                }
            }
        }
    }
    return result;
}

vector<int> diffWaysToCompute(string expression) {
    // 消除第一个字符是符号的可能性
    if(expression[0]=='-' || expression[0]=='+')
        expression="0"+expression;
    return diffWaysToCompute(expression, 0, expression.length());
}