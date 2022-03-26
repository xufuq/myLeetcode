#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <stack>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;


// 首先需要实现一个堆栈计算器
// 超出时间限制
bool cal(string &str, int target) {
    stack<long> nums;
    stack<char> buf;

    int sIndex = 0, len = str.length();
    for(int i=0;i<len;i++) {
        if(!isdigit(str[i]) || i==len-1) { // 不是数字或者到达末尾
        string numStr;
            int num2;
            if(!isdigit(str[i]))
                numStr=str.substr(sIndex, i-sIndex);
            else
                numStr=str.substr(sIndex, i-sIndex+1);
            if(numStr[0]=='0' && numStr.length()>1) {
                // 不合法数字组成
                return false;
            }
            num2=stoi(numStr);
            sIndex = i+1;
            if(!buf.empty() && buf.top()=='*') {
                int n=nums.top();
                nums.pop(); //
                n*=num2; //
                nums.push(n);
                buf.pop();
            }
            else
                nums.push(num2);
            if(i!=len-1)
                buf.push(str[i]);
        }
    }
    while(!buf.empty()) {
        int num2=nums.top();
        nums.pop();
        int num1=nums.top();
        nums.pop();
        if(buf.top()=='-')
            nums.push(num1-num2);
        else
            nums.push(num1+num2);
        buf.pop();
    }
    return nums.top()==target;
}

void addOperators(string &num, int index, string &path, int &target, vector<string> &result) {
    // 符号已经全部添加完毕
    if(index==num.size()) {
        if(cal(path, target)) 
            result.push_back(path);
        return;
    }
    // 还没有到最后一个数字
    path+="+"+string(1, num[index]);
    addOperators(num, index+1, path, target, result);
    path[path.length()-2]='-';
    addOperators(num, index+1, path, target, result);
    path[path.length()-2]='*';
    addOperators(num, index+1, path, target, result);

    path.pop_back();
    path.pop_back();
    path+=string(1, num[index]);
    addOperators(num, index+1, path, target, result);

    path.pop_back(); // 恢复现场
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    string path;
    path.push_back(num[0]);
    addOperators(num, 1, path, target, result);
    return result;
}