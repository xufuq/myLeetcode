#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 先用栈顺序保存
// 访问完所有之后再转换为队列的特性
vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size(), -1); //
    stack<int> st;
    for(int i = 0; i < nums.size();++i) {
        while(!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    // 相当于走了两遍
    for(int i = 0; i < nums.size();) {
        if(nums[i]>nums[st.top()]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        else ++i;
    }
    return result;
}