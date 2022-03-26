#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 单调栈中按递减顺序存储柱子高度
// 如果有大于等于，则弹出小的并按大小顺序压入新的
// 弹出时需要计算两个柱子之间的容量大小，所以要记录上一次弹出的高度
int trap(vector<int>& height) {
    int len = height.size();
    int result=0;
    stack<int> st; // 压入的是坐标，这样可以计算底的宽度
    for(int i=0;i<len;++i){
        while(!st.empty() && height[i]>=height[st.top()]){
            int lastIndex = st.top();
            st.pop();
            int minHeight=0;
            if(st.empty()) minHeight=0;
            else minHeight =min(height[st.top()], height[i]); // 上一个节点的小边界
            if(minHeight-height[lastIndex]>0)
                result += (minHeight-height[lastIndex])*(i-st.top()-1); // 这里减的是st.top()而不是lastIndex
        }
        st.push(i);
    }
    return result;
}

// 双指针解法也比较容易理解
// 从左右两边逐个找最小的，这样就能找到在每个高度上能够围起来的空地的范围

int main(){
    vector<int> height = {4,2,0,3,2,5};
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height);
}