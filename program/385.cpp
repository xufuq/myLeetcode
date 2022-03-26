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

class NestedInteger {
public:
  // Constructor initializes an empty nested list.
   NestedInteger();
   // Constructor initializes a single integer.
   NestedInteger(int value);
   // Return true if this NestedInteger holds a single integer, rather than a nested list.
   bool isInteger() const;
   // Return the single integer that this NestedInteger holds, if it holds a single integer
   // The result is undefined if this NestedInteger holds a nested list
   int getInteger() const;
   // Set this NestedInteger to hold a single integer.
   void setInteger(int value);
   // Set this NestedInteger to hold a nested list and adds a nested integer to it.
   void add(const NestedInteger &ni);
   // Return the nested list that this NestedInteger holds, if it holds a nested list
   // The result is undefined if this NestedInteger holds a single integer
   const vector<NestedInteger> &getList() const;
};


// 递归实现
// 遇到一个左括号就实现一层递归
// 如果只有一个数字，就设置数字
// 如果有多个数字，就是变成列表形式
// index输入时是开始的位置
// 当递归调用完成后就变成了当前需要在访问的位置
NestedInteger deserialize(string &s, int &index) {
    // s[Index]一定是左括号
    NestedInteger result(0); // 默认包含一个列表
    if(s[index]=='[') {
        ++index;
        result=NestedInteger();
    }
    while(index<s.length()) {
        if(isdigit(s[index]) || s[index]=='-') {
            int sI=index;
            while(isdigit(s[index]) || s[index]=='-')
                ++index;
            int num=stoi(s.substr(sI, index-sI));
            if(result.isInteger()) // 一个刚初始化的空列表
                result.setInteger(num);
            else 
                result.add(NestedInteger(num));
        } else if(s[index]=='[') {
            NestedInteger temp=deserialize(s, index);
            result.add(temp);
        } else if(s[index]==']') {
            ++index;
            return result;
        } else
            ++index;
    }
    return result;
}

NestedInteger deserialize(string s) {
    int index=0;
    return deserialize(s, index);
}