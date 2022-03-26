#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 先用动态规划做dp[i][j]中存的是这个范围中的最低高度,首尾都包括
// 用一个result单独存储最大的结果
// 超出时间限制，这里用二维数组复杂度太高
int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int result=0;
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(i==j){
                dp[i][i]=heights[i];
                result=max(result, heights[i]);
            }
            else{
                dp[i][j]=min(dp[i][j-1], heights[j]);
                result = max(result, dp[i][j]*(j-i+1));
            }
        }
    }
    return result;
}

// 单调栈的做法解读
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.insert(heights.begin(), 0); // 数组头部加入元素0，这样保证st中始终都有元素
    heights.push_back(0); // 数组尾部加入元素0，尾部加入0可以计算所有可能性，不会导致最后st中有剩余
    st.push(0);
    int result = 0;
    // 第一个元素已经入栈，从下表1开始
    for (int i = 1; i < heights.size(); i++) {
        // 注意heights[i] 是和heights[st.top()] 比较 ，st.top()是下表
        if (heights[i] > heights[st.top()]) {
            st.push(i);
        } else if (heights[i] == heights[st.top()]) { // 这里遇到相同的弹出，所以记录的是相邻出现的元素的最后一个出现的位置
            st.pop(); // 这个可以加，可以不加，效果一样，思路不同
            st.push(i);
        } else {
            while (heights[i] < heights[st.top()]) { // 注意是while
                int mid = st.top();
                st.pop();
                int left = st.top(); // 前边还有一个0，最少也是从头开始
                int right = i;
                int w = right - left - 1; // 这里其实就是当前堆栈顶部元素的个数
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
    }
    return result;
}



int main(){
    // vector<int> heights = {2,1,5,6,2,3};
    vector<int> heights = {2,4};
    cout << largestRectangleArea(heights);
}