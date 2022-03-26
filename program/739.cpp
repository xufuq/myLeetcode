#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int len = temperatures.size();
    vector<int> result(len, 0);
    for(int i=len-2;i>=0;--i){ // 倒数第一个肯定是0
        if(temperatures[i]<temperatures[i+1]) result[i]=1;
        else if(result[i+1]!=0){ // 有值
            int j=i+1+result[i+1];
            while(j<len){
                if(temperatures[i]< temperatures[j]) {
                    result[i]=j-i;
                    break;
                }
                else if(result[j]!=0) j+=result[j];
                else break;
            }
        }
    }
    return result;
}

// 单调栈解法
// 元素越大，越靠近栈底，即越晚弹出
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int len = temperatures.size();
    vector<int> result(len, 0);
    stack<int> st; // 栈中压入的是坐标
    for(int i=0;i<len;++i){
        while(!st.empty() && temperatures[i]>temperatures[st.top()]){
            result[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}