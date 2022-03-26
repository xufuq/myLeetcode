#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;


// 即在一个范围内，左括号的数量总是大于等于右括号
// 用一个一维int数组记录，小于0表示右括号多，大于0表示左括号多
// 动态规划做
int longestValidParentheses(string s) {
    vector<int> result(2, 0); // 记录最长子串的起始位置和终止位置,即等于0时查看是否需要更换
    int len = s.length();
    vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
    for(int i=1;i<=len;++i){
        for(int j=i;j<=len;++j){ // j一定大于等于i
            if(s[j]==')') dp[i][j]=dp[i][j-1]-1;
            else if(dp[i][j-1]<0) dp[i][j]=1;
            else if(dp[i][j-1]>0) dp[i][j]=dp[i][j-1]+1;
            else { // 等于0，看是否更新坐标

            }
        }
    }
}

// 感觉动态规划还是太费时
// 用双指针做感觉更好一些
int longestValidParentheses(string s) {
    int len = s.length();
    if(len==0 || len==1) return 0;
    int result=0; // 记录最长子串的起始位置和终止位置,即等于0时查看是否需要更换
    int count=0; // 记录当前的左右括号，小于0表示右括号多，大于0表示左括号多
    int i=0;
    while(i<len){
        count=0;
        for(int j=i;j<len && count>=0;++j){
            if(s[j]=='(') ++count;
            else --count;
            if(count==0 && j-i>result)
                result=j-i+1;
        }
        if(count==0){ // 这之后没有比这更大的了,j已经到达末尾
            break;
        }
        while(count<0 && i<len){
            if(s[i]=='(') --count;
            else ++count;
            ++i;
        }
        if(count>0 && i<len){
            if(s[i]=='(') --count;
            else ++count;
            ++i;
        }
    }
    return result;
}

// 用堆栈
// 官方解法，栈底元素是第一个没有被匹配的右括号的下标
// 这个栈底元素可以保证两个连续弹出的符合条件的字符串不能相加的问题，直接在计算下标的时候就相加
int longestValidParentheses(string s) {
    int maxans = 0;
    stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxans = max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
}

